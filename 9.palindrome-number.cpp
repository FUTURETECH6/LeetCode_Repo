/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (50.31%)
 * Likes:    3317
 * Dislikes: 1743
 * Total Accepted:    1.3M
 * Total Submissions: 2.5M
 * Testcase Example:  '121'
 *
 * Given an integer x, return true if x is palindrome integer.
 *
 * An integer is a palindrome when it reads the same backward as forward. For
 * example, 121 is palindrome while 123 is not.
 *
 *
 * Example 1:
 *
 *
 * Input: x = 121
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: x = -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 *
 *
 * Example 3:
 *
 *
 * Input: x = 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a
 * palindrome.
 *
 *
 * Example 4:
 *
 *
 * Input: x = -101
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * -2^31 <= x <= 2^31 - 1
 *
 *
 *
 * Follow up: Could you solve it without converting the integer to a string?
 */

#include <iostream>
using namespace std;
// @lc code=start
class Solution {
  public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        int mask;  // 1000 for 1221, 1000 for 1000
        for (mask = 1; mask <= x / 10; mask *= 10)
            ;

        for (; x; x = (x - x / mask * mask) / 10, mask /= 100)
            if (x % 10 != x / mask)
                return false;

        return true;
    }
};
// @lc code=end
