/*
 * @lc app=leetcode id=623 lang=cpp
 *
 * [623] Add One Row to Tree
 *
 * https://leetcode.com/problems/add-one-row-to-tree/description/
 *
 * algorithms
 * Medium (53.82%)
 * Likes:    1236
 * Dislikes: 170
 * Total Accepted:    82K
 * Total Submissions: 152.2K
 * Testcase Example:  '[4,2,6,3,1,5]\n1\n2'
 *
 * Given the root of a binary tree and two integers val and depth, add a row of
 * nodes with value val at the given depth depth.
 *
 * Note that the root node is at depth 1.
 *
 * The adding rule is:
 *
 *
 * Given the integer depth, for each not null tree node cur at the depth depth
 * - 1, create two tree nodes with value val as cur's left subtree root and
 * right subtree root.
 * cur's original left subtree should be the left subtree of the new left
 * subtree root.
 * cur's original right subtree should be the right subtree of the new right
 * subtree root.
 * If depth == 1 that means there is no depth depth - 1 at all, then create a
 * tree node with value val as the new root of the whole original tree, and the
 * original tree is the new root's left subtree.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: root = [4,2,6,3,1,5], val = 1, depth = 2
 * Output: [4,1,1,2,null,null,6,3,1,5]
 *
 *
 * Example 2:
 *
 *
 * Input: root = [4,2,null,3,1], val = 1, depth = 3
 * Output: [4,2,null,1,1,3,null,null,1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 10^4].
 * The depth of the tree is in the range [1, 10^4].
 * -100 <= Node.val <= 100
 * -10^5 <= val <= 10^5
 * 1 <= depth <= the depth of tree + 1
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

class Solution {
  public:
    /**
     * @brief for each not null tree node cur at the depth depth - 1, create two tree nodes with value val as cur's left subtree root and right subtree root.
     *        cur's original left subtree should be the left subtree of the new left subtree root. cur's original right subtree should be the right subtree of the new right subtree root.
     *        If depth == 1 that means there is no depth depth - 1 at all, then create a tree node with value val as the new root of the whole original tree, and the original tree is the new root's
     * left subtree.
     *
     * @param root at depth 1
     * @param val
     * @param depth
     * @return TreeNode*
     */
    TreeNode *addOneRow(TreeNode *root, int val, int depth) {
        switch (depth) {
            case 1: return new TreeNode(val, root, nullptr);

            case 2:
                root->left  = new TreeNode(val, root->left, nullptr);
                root->right = new TreeNode(val, nullptr, root->right);
                return root;

            default:
                if (root->left)
                    root->left = addOneRow(root->left, val, depth - 1);
                if (root->right)
                    root->right = addOneRow(root->right, val, depth - 1);
                return root;
        }
    }
};

// @lc code=end
