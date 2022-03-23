/*
 * @lc app=leetcode id=2165 lang=cpp
 *
 * [2165] Smallest Value of the Rearranged Number
 *
 * https://leetcode.com/problems/smallest-value-of-the-rearranged-number/description/
 *
 * algorithms
 * Medium (50.58%)
 * Likes:    273
 * Dislikes: 8
 * Total Accepted:    19.2K
 * Total Submissions: 37.9K
 * Testcase Example:  '310'
 *
 * You are given an integer num. Rearrange the digits of num such that its
 * value is minimized and it does not contain any leading zeros.
 *
 * Return the rearranged number with minimal value.
 *
 * Note that the sign of the number does not change after rearranging the
 * digits.
 *
 *
 * Example 1:
 *
 *
 * Input: num = 310
 * Output: 103
 * Explanation: The possible arrangements for the digits of 310 are 013, 031,
 * 103, 130, 301, 310.
 * The arrangement with the smallest value that does not contain any leading
 * zeros is 103.
 *
 *
 * Example 2:
 *
 *
 * Input: num = -7605
 * Output: -7650
 * Explanation: Some possible arrangements for the digits of -7605 are -7650,
 * -6705, -5076, -0567.
 * The arrangement with the smallest value that does not contain any leading
 * zeros is -7650.
 *
 *
 *
 * Constraints:
 *
 *
 * -10^15 <= num <= 10^15
 *
 *
 */

#include "misc.h"
#include <iostream>
using namespace std;
// @lc code=start

#include <algorithm>
#include <cmath>
#include <deque>

class Solution {
  public:
    long long smallestNumber(long long num) {
        if (num == 0)
            return 0;

        deque<int> num_char;
        char flag = num < 0 ? -1 : 1;

        while (num) {
            num_char.push_front(flag * (char)(num % 10));
            num /= 10;
        }

        long long res = 0;
        if (flag == 1) {
            sort(num_char.begin(), num_char.end(), less<int>());
            unsigned zero_num = 0;
            while (num_char[zero_num] == 0)
                zero_num++;
            res = num_char[zero_num] * pow(10, zero_num);
            for (auto i = zero_num + 1; i < num_char.size(); i++) {
                res *= 10;
                res += num_char[i];
            }
            return res;
        } else {
            sort(num_char.begin(), num_char.end(), greater<int>());
            for (auto &i : num_char) {
                res *= 10;
                res += i;
            }
            return -res;
        }
    }
};

// @lc code=end

int main(int argc, char const *argv[]) {
    long long a = 100222;
    cout << Solution().smallestNumber(a) << endl;
    return 0;
}
