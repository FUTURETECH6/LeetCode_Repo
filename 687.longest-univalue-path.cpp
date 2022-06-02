/*
 * @lc app=leetcode id=687 lang=cpp
 *
 * [687] Longest Univalue Path
 *
 * https://leetcode.com/problems/longest-univalue-path/description/
 *
 * algorithms
 * Medium (39.22%)
 * Likes:    3061
 * Dislikes: 607
 * Total Accepted:    140.3K
 * Total Submissions: 356.6K
 * Testcase Example:  '[5,4,5,1,1,5]'
 *
 * Given the root of a binary tree, return the length of the longest path,
 * where each node in the path has the same value. This path may or may not
 * pass through the root.
 *
 * The length of the path between two nodes is represented by the number of
 * edges between them.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [5,4,5,1,1,5]
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,4,5,4,4,5]
 * Output: 2
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 10^4].
 * -1000 <= Node.val <= 1000
 * The depth of the tree will not exceed 1000.
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

using namespace std;

// @lc code=start

#include <algorithm>
#include <unordered_map>

class Solution {
  private:
    int longestUnivaluePathRootedAt(TreeNode *root) {
        static unordered_map<TreeNode *, int> lengthMap;

        if (!lengthMap.count(root)) {
            if (!root)
                lengthMap[root] = 0;
            if (root->left && root->left->val == root->val && root->right && root->right->val == root->val) {
                lengthMap[root] = max(longestUnivaluePathRootedAt(root->left), longestUnivaluePathRootedAt(root->right)) + 1;
            } else if (root->left && root->left->val == root->val) {
                lengthMap[root] = longestUnivaluePathRootedAt(root->left) + 1;
            } else if (root->right && root->right->val == root->val) {
                lengthMap[root] = longestUnivaluePathRootedAt(root->right) + 1;
            } else {
                lengthMap[root] = 0;
            }
        }
        return lengthMap[root];
    }

  public:
    int longestUnivaluePath(TreeNode *root) {
        if (!root)
            return 0;
        // return max({longestUnivaluePathRootedAt(root), longestUnivaluePath(root->left), longestUnivaluePath(root->right)});

        if (root->left && root->left->val == root->val && root->right && root->right->val == root->val) {
            return max({longestUnivaluePathRootedAt(root->left) + longestUnivaluePathRootedAt(root->right) + 2, longestUnivaluePath(root->left), longestUnivaluePath(root->right)});
        } else if (root->left && root->left->val == root->val) {
            return max({longestUnivaluePathRootedAt(root->left) + 1, longestUnivaluePath(root->left), longestUnivaluePath(root->right)});
        } else if (root->right && root->right->val == root->val) {
            return max({longestUnivaluePathRootedAt(root->right) + 1, longestUnivaluePath(root->left), longestUnivaluePath(root->right)});
        } else {
            return max(longestUnivaluePath(root->left), longestUnivaluePath(root->right));
        }
    }
};
// @lc code=end
