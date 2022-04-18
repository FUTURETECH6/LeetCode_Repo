/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 *
 * https://leetcode.com/problems/clone-graph/description/
 *
 * algorithms
 * Medium (47.00%)
 * Likes:    5554
 * Dislikes: 2462
 * Total Accepted:    700.9K
 * Total Submissions: 1.5M
 * Testcase Example:  '[[2,4],[1,3],[2,4],[1,3]]'
 *
 * Given a reference of a node in a connected undirected graph.
 *
 * Return a deep copy (clone) of the graph.
 *
 * Each node in the graph contains a value (int) and a list (List[Node]) of its
 * neighbors.
 *
 *
 * class Node {
 * ⁠   public int val;
 * ⁠   public List<Node> neighbors;
 * }
 *
 *
 *
 *
 * Test case format:
 *
 * For simplicity, each node's value is the same as the node's index
 * (1-indexed). For example, the first node with val == 1, the second node with
 * val == 2, and so on. The graph is represented in the test case using an
 * adjacency list.
 *
 * An adjacency list is a collection of unordered lists used to represent a
 * finite graph. Each list describes the set of neighbors of a node in the
 * graph.
 *
 * The given node will always be the first node with val = 1. You must return
 * the copy of the given node as a reference to the cloned graph.
 *
 *
 * Example 1:
 *
 *
 * Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
 * Output: [[2,4],[1,3],[2,4],[1,3]]
 * Explanation: There are 4 nodes in the graph.
 * 1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val =
 * 4).
 * 2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val =
 * 3).
 * 3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val =
 * 4).
 * 4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val =
 * 3).
 *
 *
 * Example 2:
 *
 *
 * Input: adjList = [[]]
 * Output: [[]]
 * Explanation: Note that the input contains one empty list. The graph consists
 * of only one node with val = 1 and it does not have any neighbors.
 *
 *
 * Example 3:
 *
 *
 * Input: adjList = []
 * Output: []
 * Explanation: This an empty graph, it does not have any nodes.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the graph is in the range [0, 100].
 * 1 <= Node.val <= 100
 * Node.val is unique for each node.
 * There are no repeated edges and no self-loops in the graph.
 * The Graph is connected and all nodes can be visited starting from the given
 * node.
 *
 *
 */

#include "misc.h"
using namespace std;

// Definition for a Node.
class Node {
  public:
    int val;
    vector<Node *> neighbors;
    Node() {
        val       = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val) {
        val       = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors) {
        val       = _val;
        neighbors = _neighbors;
    }
};

// @lc code=start

#include <unordered_map>

class Solution {
  private:
    unordered_map<int, Node *> nodeMap;

  public:
    Node *cloneGraph(Node *node) {
        if (node == nullptr)
            return nullptr;
        if (nodeMap.count(node->val))  // node already clone
            return nodeMap[node->val];

        nodeMap[node->val] = new Node(node->val);

        for (auto &oldNeighbor : node->neighbors) {
            if (!nodeMap.count(oldNeighbor->val))  // clone neighbor if hasn't been cloned
                nodeMap[oldNeighbor->val] = cloneGraph(oldNeighbor);
            nodeMap[node->val]->neighbors.push_back(nodeMap[oldNeighbor->val]);
        }

        return nodeMap[node->val];
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    auto n1 = new Node(1), n2 = new Node(2), n3 = new Node(3), n4 = new Node(4);
    n1->neighbors = {n2, n4};
    n2->neighbors = {n1, n3};
    n3->neighbors = {n2, n4};
    n4->neighbors = {n1, n3};

    auto newGraph = Solution().cloneGraph(n1);
    return 0;
}
