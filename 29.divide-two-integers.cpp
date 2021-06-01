/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (16.95%)
 * Likes:    1837
 * Dislikes: 7031
 * Total Accepted:    372.9K
 * Total Submissions: 2.2M
 * Testcase Example:  '10\n3'
 *
 * Given two integers dividend and divisor, divide two integers without using
 * multiplication, division, and mod operator.
 *
 * Return the quotient after dividing dividend by divisor.
 *
 * The integer division should truncate toward zero, which means losing its
 * fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) =
 * -2.
 *
 * Note: Assume we are dealing with an environment that could only store
 * integers within the 32-bit signed integer range: [−2^31, 2^31 − 1]. For this
 * problem, assume that your function returns 2^31 − 1 when the division result
 * overflows.
 *
 *
 * Example 1:
 *
 *
 * Input: dividend = 10, divisor = 3
 * Output: 3
 * Explanation: 10/3 = truncate(3.33333..) = 3.
 *
 *
 * Example 2:
 *
 *
 * Input: dividend = 7, divisor = -3
 * Output: -2
 * Explanation: 7/-3 = truncate(-2.33333..) = -2.
 *
 *
 * Example 3:
 *
 *
 * Input: dividend = 0, divisor = 1
 * Output: 0
 *
 *
 * Example 4:
 *
 *
 * Input: dividend = 1, divisor = 1
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * -2^31 <= dividend, divisor <= 2^31 - 1
 * divisor != 0
 *
 *
 */

// @lc code=start
#include <limits.h>

class Solution {
  public:
    inline int divide(int dividend, int divisor) {
        return dividend == INT_MIN && divisor == -1 ? INT_MAX : dividend / divisor;
    }
};
// @lc code=end
