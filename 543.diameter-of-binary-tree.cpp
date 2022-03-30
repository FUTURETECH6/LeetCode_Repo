/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 *
 * https://leetcode.com/problems/diameter-of-binary-tree/description/
 *
 * algorithms
 * Easy (53.90%)
 * Likes:    7476
 * Dislikes: 467
 * Total Accepted:    695.1K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given the root of a binary tree, return the length of the diameter of the
 * tree.
 *
 * The diameter of a binary tree is the length of the longest path between any
 * two nodes in a tree. This path may or may not pass through the root.
 *
 * The length of a path between two nodes is represented by the number of edges
 * between them.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,3,4,5]
 * Output: 3
 * Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,2]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 10^4].
 * -100 <= Node.val <= 100
 *
 *
 */

#include "misc.h"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start

#include <algorithm>
#include <map>
#include <numeric>

class Solution {
  private:
    int getDepth(TreeNode *p) {
        static map<TreeNode *, int> depth_map;

        if (!p)
            return 0;
        if (depth_map.count(p) == 1)
            return depth_map[p];

        depth_map[p] = max(getDepth(p->left), getDepth(p->right)) + 1;
        return depth_map[p];
    }

  public:
    int diameterOfBinaryTree(TreeNode *root) {
        if (!root)
            return 0;

        return max({diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right), getDepth(root->left) + getDepth(root->right)});
    }
};

// @lc code=end
