/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (26.00%)
 * Likes:    4757
 * Dislikes: 7258
 * Total Accepted:    1.5M
 * Total Submissions: 5.9M
 * Testcase Example:  '123'
 *
 * Given a signed 32-bit integer x, return x with its digits reversed. If
 * reversing x causes the value to go outside the signed 32-bit integer range
 * [-2^31, 2^31 - 1], then return 0.
 *
 * Assume the environment does not allow you to store 64-bit integers (signed
 * or unsigned).
 *
 *
 * Example 1:
 * Input: x = 123
 * Output: 321
 * Example 2:
 * Input: x = -123
 * Output: -321
 * Example 3:
 * Input: x = 120
 * Output: 21
 * Example 4:
 * Input: x = 0
 * Output: 0
 *
 *
 * Constraints:
 *
 *
 * -2^31 <= x <= 2^31 - 1
 *
 *
 */
#include <iostream>
using namespace std;
// @lc code=start
#include <limits.h>

class Solution {
  public:
    int reverse(int x) {
        long res = 0;

        for (; x; res += x % 10, x /= 10, res *= x ? 10 : 1)
            ;

        return res > INT_MAX || res < INT_MIN ? 0 : res;
    }
};
// @lc code=end

/*
1. 一开始是用`res *= 10`，最后再`return negFlag ? -res / 10 : res /
10;`，但是这样在计算过程中res可能会超过int的范围，因此改成现在这样，不会有多余的x10操作
2. 后来发现他要对res进行溢出判断，所以就不能仅用int了，要改成long
3. 另外，这里对x取绝对值是存在问题的，因为 -INT_MIN = INT_MAX +
1，所以会溢出，所以改成直接对负数一起操作
    * 注意 -12 % 10 == -2 而不是 8
*/