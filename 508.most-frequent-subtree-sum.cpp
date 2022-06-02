/*
 * @lc app=leetcode id=508 lang=cpp
 *
 * [508] Most Frequent Subtree Sum
 *
 * https://leetcode.com/problems/most-frequent-subtree-sum/description/
 *
 * algorithms
 * Medium (62.50%)
 * Likes:    1472
 * Dislikes: 224
 * Total Accepted:    107K
 * Total Submissions: 170.5K
 * Testcase Example:  '[5,2,-3]'
 *
 * Given the root of a binary tree, return the most frequent subtree sum. If
 * there is a tie, return all the values with the highest frequency in any
 * order.
 *
 * The subtree sum of a node is defined as the sum of all the node values
 * formed by the subtree rooted at that node (including the node itself).
 *
 *
 * Example 1:
 *
 *
 * Input: root = [5,2,-3]
 * Output: [2,-3,4]
 *
 *
 * Example 2:
 *
 *
 * Input: root = [5,2,-5]
 * Output: [2]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 10^4].
 * -10^5 <= Node.val <= 10^5
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

#include "misc.h"
using namespace std;

// @lc code=start

#include <algorithm>
#include <unordered_map>

class Solution {
  private:
    int getSum(TreeNode *root) {
        static unordered_map<TreeNode *, int> sumMap;

        if (!root)
            return 0;

        if (sumMap.count(root) == 0)
            sumMap[root] = root->val + getSum(root->left) + getSum(root->right);
        return sumMap[root];
    }

    void updateCountMap(TreeNode *root, unordered_map<int, unsigned> &countMap) {
        if (!root)
            return;
        countMap[getSum(root)]++;
        updateCountMap(root->left, countMap);
        updateCountMap(root->right, countMap);
    }

  public:
    vector<int> findFrequentTreeSum(TreeNode *root) {
        unordered_map<int, unsigned> countMap;  // <sum, count>
        updateCountMap(root, countMap);

        vector<int> result;

        auto maxCount = max_element(countMap.begin(), countMap.end(), [](auto &p1, auto &p2) { return p1.second < p2.second; })->second;
        for (auto &[sum, count] : countMap) {
            if (count == maxCount)
                result.push_back(sum);
        }
        return result;
    }
};
// @lc code=end
