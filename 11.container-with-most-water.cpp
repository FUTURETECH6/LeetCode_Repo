/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (52.97%)
 * Likes:    9534
 * Dislikes: 717
 * Total Accepted:    950.1K
 * Total Submissions: 1.8M
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which,
 * together with the x-axis forms a container, such that the container contains
 * the most water.
 *
 * Notice that you may not slant the container.
 *
 *
 * Example 1:
 *
 *
 * Input: height = [1,8,6,2,5,4,8,3,7]
 * Output: 49
 * Explanation: The above vertical lines are represented by array
 * [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the
 * container can contain is 49.
 *
 *
 * Example 2:
 *
 *
 * Input: height = [1,1]
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: height = [4,3,2,1,4]
 * Output: 16
 *
 *
 * Example 4:
 *
 *
 * Input: height = [1,2,1]
 * Output: 2
 *
 *
 *
 * Constraints:
 *
 *
 * n == height.length
 * 2 <= n <= 10^5
 * 0 <= height[i] <= 10^4
 *
 *
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int maxArea(vector<int> &height) {
        int res = 0;
        int l = 0, r = height.size() - 1;
        int curHeight;

        while (l < r) {
            curHeight = min(height[l], height[r]);
            res       = max(res, (r - l) * curHeight);
            while (height[l] <= curHeight && l < r)
                l++;
            while (height[r] <= curHeight && l < r)
                r--;
        }

        return res;
    }
};
// @lc code=end

/* Dynamic Programming O(n^2) */
// class Solution {
//   public:
//     int maxArea(vector<int> &height) {
//         const int lineNum = height.size();
//         vector<vector<int>> dp(lineNum, vector<int>(lineNum, 0));

//         for (int sep = 1; sep < lineNum; sep++) {
//             for (int i = 0; i < lineNum - sep; i++) {
//                 dp[i][i + sep] = this->max(sep * this->min(height[i], height[i + sep]),
//                     dp[i][i + sep - 1], dp[i + 1][i + sep]);
//             }
//         }
//         return dp[0][lineNum - 1];
//     }

//   private:
//     inline int max(int a, int b, int c) { return a > b ? (a > c ? a : c) : (b > c ? b : c);
//     } inline int min(int a, int b) { return a < b ? a : b; }
// };