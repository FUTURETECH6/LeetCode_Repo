/*
 * @lc app=leetcode id=1766 lang=cpp
 *
 * [1766] Tree of Coprimes
 *
 * https://leetcode.com/problems/tree-of-coprimes/description/
 *
 * algorithms
 * Hard (38.09%)
 * Likes:    224
 * Dislikes: 17
 * Total Accepted:    5.5K
 * Total Submissions: 14.2K
 * Testcase Example:  '[2,3,3,2]\n[[0,1],[1,2],[1,3]]'
 *
 * There is a tree (i.e., a connected, undirected graph that has no cycles)
 * consisting of n nodes numbered from 0 to n - 1 and exactly n - 1 edges. Each
 * node has a value associated with it, and the root of the tree is node 0.
 *
 * To represent this tree, you are given an integer array nums and a 2D array
 * edges. Each nums[i] represents the i^th node's value, and each edges[j] =
 * [uj, vj] represents an edge between nodes uj and vj in the tree.
 *
 * Two values x and y are coprime if gcd(x, y) == 1 where gcd(x, y) is the
 * greatest common divisor of x and y.
 *
 * An ancestor of a node i is any other node on the shortest path from node i
 * to the root. A node is not considered an ancestor of itself.
 *
 * Return an array ans of size n, where ans[i] is the closest ancestor to node
 * i such that nums[i] and nums[ans[i]] are coprime, or -1 if there is no such
 * ancestor.
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input: nums = [2,3,3,2], edges = [[0,1],[1,2],[1,3]]
 * Output: [-1,0,0,1]
 * Explanation: In the above figure, each node's value is in parentheses.
 * - Node 0 has no coprime ancestors.
 * - Node 1 has only one ancestor, node 0. Their values are coprime (gcd(2,3)
 * == 1).
 * - Node 2 has two ancestors, nodes 1 and 0. Node 1's value is not coprime
 * (gcd(3,3) == 3), but node 0's
 * ⁠ value is (gcd(2,3) == 1), so node 0 is the closest valid ancestor.
 * - Node 3 has two ancestors, nodes 1 and 0. It is coprime with node 1
 * (gcd(3,2) == 1), so node 1 is its
 * ⁠ closest valid ancestor.
 *
 *
 * Example 2:
 *
 *
 *
 *
 * Input: nums = [5,6,10,2,3,6,15], edges =
 * [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]
 * Output: [-1,0,-1,0,0,0,-1]
 *
 *
 *
 * Constraints:
 *
 *
 * nums.length == n
 * 1 <= nums[i] <= 50
 * 1 <= n <= 10^5
 * edges.length == n - 1
 * edges[j].length == 2
 * 0 <= uj, vj < n
 * uj != vj
 *
 *
 */

#include "misc.h"
using namespace std;
#include <chrono>

#define DEBUG

// @lc code=start

#include <algorithm>
#include <map>
#include <numeric>
#include <set>
#include <unordered_map>
#include <unordered_set>

struct Node {
    unsigned index;
    int val;

    Node *parent;

    Node(unsigned index, int val) : index(index), val(val), parent(nullptr) {}
};

template <typename Container>  // we can make this generic for any container [1]
struct container_hash {
    std::size_t operator()(Container const &V) const {
        int hash = V.size();
        for (auto &i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

struct edge_hash {
    std::size_t operator()(vector<int> const &edge) const { return ((size_t)edge[0] << 17) | edge[1]; }
};

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;
    }
};

class Solution {
  private:
    unordered_map<int, unsigned> depthMap = {{0, 0}};

    int gcd(int a, int b) {
        // static unordered_map<pair<int, int>, int, pair_hash> dict;
        // if (dict.count({min(a, b), max(a, b)}) == 0)
        //     dict[{min(a, b), max(a, b)}] = b > 0 ? gcd(b, a % b) : a;
        // return dict[{min(a, b), max(a, b)}];
        return b > 0 ? gcd(b, a % b) : a;
    }

    bool updateDepth(vector<int> edge) {
        switch (depthMap.count(edge[0]) << 1 | depthMap.count(edge[1])) {
            case 0b00: return false;
            case 0b01: depthMap[edge[0]] = depthMap[edge[1]] + 1; break;
            case 0b10: depthMap[edge[1]] = depthMap[edge[0]] + 1; break;
            default: return false;
        }
        return true;
    }

  public:
    vector<int> getCoprimes(vector<int> &nums, vector<vector<int>> &edges) {
#ifdef DEBUG
        using namespace std::chrono;
        vector<int64_t> time;
        time.push_back(duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count());
#endif
        vector<Node *> nodes;
        for (unsigned i = 0; i < nums.size(); i++)
            nodes.push_back(new Node(i, nums[i]));

        // auto edges_set_tmp = set<vector<int>>(edges.begin(), edges.end());

        // unordered_map<int, unordered_set<int>> connected_graph;
        // for (auto &edge : edges) {
        //     if (connected_graph.count(edge[0]))
        //         connected_graph[edge[0]].insert(edge[1]);
        //     else
        //         connected_graph[edge[0]] = {edge[1]};
        //     if (connected_graph.count(edge[1]))
        //         connected_graph[edge[1]].insert(edge[0]);
        //     else
        //         connected_graph[edge[1]] = {edge[0]};
        // }

        auto edges_set = unordered_set<vector<int>, edge_hash>(edges.begin(), edges.end());

#ifdef DEBUG
        time.push_back(duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count());
        cout << "[*] Time to prepare: " << time.back() - *(time.end() - 2) << endl;
#endif

        //         while (!edges_set_tmp.empty()) {
        //             for (auto p = edges_set_tmp.begin(); p != edges_set_tmp.end();)
        //                 if (updateDepth(*p))
        //                     edges_set_tmp.erase(p++);
        //                 else
        //                     p++;
        //         }

        // #ifdef DEBUG
        //         time.push_back(duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count());
        //         cout << "[*] Time set parent: " << time.back() - *(time.end() - 2) << endl;
        // #endif

        //         sort(edges.begin(), edges.end(), [this](vector<int> &a, vector<int> &b) { return min(this->depthMap[a[0]], this->depthMap[a[1]]) < min(this->depthMap[b[0]], this->depthMap[b[1]]);
        //         });

        // #ifdef DEBUG
        //         time.push_back(duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count());
        //         cout << "[*] Time sort: " << time.back() - *(time.end() - 2) << endl;
        // #endif

        //         for (auto p = edges.begin(); p < edges.end();) {
        //             if ((p->at(0) && p->at(1)) == 0) {  // contains root
        //                 nodes[p->at(0) | p->at(1)]->parent = nodes[0];
        //             } else {                                                                             // no root
        //                 if (nodes[p->at(0)]->parent == nullptr && nodes[p->at(1)]->parent == nullptr) {  // 00
        //                     p++;
        //                     continue;
        //                 } else if (nodes[p->at(0)]->parent != nullptr && nodes[p->at(1)]->parent != nullptr) {  // 11
        //                     cout << "Theoretically unreachable" << endl;
        //                 } else if (nodes[p->at(0)]->parent != nullptr)  // 10
        //                     nodes[p->at(1)]->parent = nodes[p->at(0)];
        //                 else if (nodes[p->at(1)]->parent != nullptr)  // 01
        //                     nodes[p->at(0)]->parent = nodes[p->at(1)];
        //             }
        //             // edges.erase(p);
        //             p++;
        //         }

        while (!edges_set.empty()) {
#ifdef DEBUG
            cout << "while count; edges_set.size() = " << edges_set.size() << endl;
#endif
            for (auto p = edges_set.begin(); p != edges_set.end();) {
                if ((p->at(0) && p->at(1)) == 0) {  // contains root
                    nodes[p->at(0) | p->at(1)]->parent = nodes[0];
                } else {                                                                             // no root
                    if (nodes[p->at(0)]->parent == nullptr && nodes[p->at(1)]->parent == nullptr) {  // 00
                        p++;
                        continue;
                    } else if (nodes[p->at(0)]->parent != nullptr && nodes[p->at(1)]->parent != nullptr) {  // 11
                        cout << "Theoretically unreachable" << endl;
                    } else if (nodes[p->at(0)]->parent != nullptr)  // 10
                        nodes[p->at(1)]->parent = nodes[p->at(0)];
                    else if (nodes[p->at(1)]->parent != nullptr)  // 01
                        nodes[p->at(0)]->parent = nodes[p->at(1)];
                }
                edges_set.erase(p++);
            }
        }

#ifdef DEBUG
        time.push_back(duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count());
        cout << "[*] Time set parent: " << time.back() - *(time.end() - 2) << endl;
#endif

        vector<int> result;
        for (auto &node : nodes) {
            bool found = false;
            for (auto p = node->parent; p; p = p->parent) {
                if (gcd(p->val, node->val) == 1) {
                    found = true;
                    result.push_back(p->index);
                    break;
                }
            }
            if (!found)
                result.push_back(-1);
        }

#ifdef DEBUG
        time.push_back(duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count());
        cout << "[*] Time find gcd:   " << time.back() - *(time.end() - 2) << endl;
#endif

        return result;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    // vector<int> nums          = {5, 6, 10, 2, 3, 6, 15};
    // vector<vector<int>> edges = {{1, 3}, {0, 1}, {0, 2}, {1, 4}, {2, 5}, {2, 6}};

    // vector<int> nums = {
    //     9, 16, 30, 23, 33, 35, 9, 47, 39, 46, 16, 38, 5, 49, 21, 44, 17, 1, 6, 37, 49, 15, 23, 46, 38, 9, 27, 3, 24, 1, 14, 17, 12, 23, 43, 38, 12, 4, 8, 17, 11, 18, 26, 22, 49, 14, 9};
    // vector<vector<int>> edges = {{17, 0}, {30, 17}, {41, 30}, {10, 30}, {13, 10}, {7, 13}, {6, 7}, {45, 10}, {2, 10}, {14, 2}, {40, 14}, {28, 40}, {29, 40}, {8, 29}, {15, 29}, {26, 15}, {23, 40},
    //     {19, 23}, {34, 19}, {18, 23}, {42, 18}, {5, 42}, {32, 5}, {16, 32}, {35, 14}, {25, 35}, {43, 25}, {3, 43}, {36, 25}, {38, 36}, {27, 38}, {24, 36}, {31, 24}, {11, 31}, {39, 24}, {12, 39},
    //     {20, 12}, {22, 12}, {21, 39}, {1, 21}, {33, 1}, {37, 1}, {44, 37}, {9, 44}, {46, 2}, {4, 46}};
    // // [-1,21,17,43,10,42,7,13,29,44,17,31,39,10,10,29,32,0,40,23,12,39,12,40,25,35,15,38,40,40,17,24,5,1,19,14,17,21,25,24,14,17,40,25,37,17,10]

    auto nums_size   = 1e+5;
    vector<int> nums = {3};     // size = 1e+5
    vector<vector<int>> edges;  // size = 1e+5 - 1
    for (unsigned i = 0; i < (nums_size - 1) / 2; i++) {
        nums.push_back(2);
        nums.push_back(6);
    }
    nums.pop_back();
    for (int i = 1; i < nums_size; i++)
        edges.push_back({0, i});

    // misc::printVec(Solution().getCoprimes(nums, edges));
    Solution().getCoprimes(nums, edges);
    return 0;
}
