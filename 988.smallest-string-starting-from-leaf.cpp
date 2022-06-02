/*
 * @lc app=leetcode id=988 lang=cpp
 *
 * [988] Smallest String Starting From Leaf
 *
 * https://leetcode.com/problems/smallest-string-starting-from-leaf/description/
 *
 * algorithms
 * Medium (48.59%)
 * Likes:    1098
 * Dislikes: 173
 * Total Accepted:    53.9K
 * Total Submissions: 110.4K
 * Testcase Example:  '[0,1,2,3,4,3,4]'
 *
 * You are given the root of a binary tree where each node has a value in the
 * range [0, 25] representing the letters 'a' to 'z'.
 *
 * Return the lexicographically smallest string that starts at a leaf of this
 * tree and ends at the root.
 *
 * As a reminder, any shorter prefix of a string is lexicographically
 * smaller.
 *
 *
 * For example, "ab" is lexicographically smaller than "aba".
 *
 *
 * A leaf of a node is a node that has no children.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [0,1,2,3,4,3,4]
 * Output: "dba"
 *
 *
 * Example 2:
 *
 *
 * Input: root = [25,1,3,1,3,0,2]
 * Output: "adz"
 *
 *
 * Example 3:
 *
 *
 * Input: root = [2,2,1,null,1,0,null,0]
 * Output: "abc"
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 8500].
 * 0 <= Node.val <= 25
 *
 *
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <iostream>
#include <string>
using namespace std;

// @lc code=start

#include <algorithm>
#include <set>
#include <unordered_map>

class Solution {
  private:
    unordered_map<TreeNode *, TreeNode *> parent;

    void findLeaf(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &leafMap) {
        if (!root)
            return;
        if (!root->left && !root->right)
            leafMap[root] = root;
        else {
            if (root->left) {
                parent[root->left] = root;
                findLeaf(root->left, leafMap);
            }
            if (root->right) {
                parent[root->right] = root;
                findLeaf(root->right, leafMap);
            }
        }
    }

  public:
    string smallestFromLeaf(TreeNode *root) {
        unordered_map<TreeNode *, TreeNode *> leafMap;  // {leaf, curNode}
        parent[root] = nullptr;
        findLeaf(root, leafMap);

        TreeNode *targetLeaf = nullptr;

        while (leafMap.size() > 1) {
            int minVal = min_element(leafMap.begin(), leafMap.end(), [](auto p1, auto p2) { return p1.second->val < p2.second->val; })->second->val;

            for (auto itor = leafMap.begin(); itor != leafMap.end();)
                if (itor->second->val != minVal)
                    itor = leafMap.erase(itor);
                else
                    itor++;
            if (leafMap.size() == 1)
                break;

            for (auto &[leaf, curNode] : leafMap)
                if (parent[curNode])
                    leafMap[leaf] = parent[curNode];
                else {
                    targetLeaf = leaf;
                    break;
                }
            if (targetLeaf)
                break;
        }

        if (!targetLeaf)
            targetLeaf = leafMap.begin()->first;

        string result = "";
        for (; targetLeaf; targetLeaf = parent[targetLeaf]) {
            result += 'a' + targetLeaf->val;
        }

        return result;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    cout << Solution().smallestFromLeaf(new TreeNode(0, new TreeNode(1, new TreeNode(3), new TreeNode(4)), new TreeNode(2, new TreeNode(3), new TreeNode(4)))) << endl;
    return 0;
}
