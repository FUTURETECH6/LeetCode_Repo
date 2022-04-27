/*
 * @lc app=leetcode id=1925 lang=cpp
 *
 * [1925] Count Square Sum Triples
 *
 * https://leetcode.com/problems/count-square-sum-triples/description/
 *
 * algorithms
 * Easy (67.18%)
 * Likes:    184
 * Dislikes: 19
 * Total Accepted:    21.2K
 * Total Submissions: 31.3K
 * Testcase Example:  '5'
 *
 * A square triple (a,b,c) is a triple where a, b, and c are integers and a^2 +
 * b^2 = c^2.
 *
 * Given an integer n, return the number of square triples such that 1 <= a, b,
 * c <= n.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 5
 * Output: 2
 * Explanation: The square triples are (3,4,5) and (4,3,5).
 *
 *
 * Example 2:
 *
 *
 * Input: n = 10
 * Output: 4
 * Explanation: The square triples are (3,4,5), (4,3,5), (6,8,10), and
 * (8,6,10).
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 250
 *
 *
 */

// @lc code=start
class Solution {
  public:
    int countTriples(int n) {
        int result = 0;

        for (int c = 1; c <= n; c++) {  // assume a < b < c
            for (int b = 1; b < c; b++) {
                for (int a = 1; a < b; a++) {
                    if (a * a + b * b == c * c)
                        result += 2;
                }
            }
        }

        return result;
    }
};
// @lc code=end
