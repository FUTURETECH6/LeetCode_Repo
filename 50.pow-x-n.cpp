/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (32.21%)
 * Likes:    4181
 * Dislikes: 5190
 * Total Accepted:    861.4K
 * Total Submissions: 2.7M
 * Testcase Example:  '2.00000\n10'
 *
 * Implement pow(x, n), which calculates x raised to the power n (i.e.,
 * x^n).
 *
 *
 * Example 1:
 *
 *
 * Input: x = 2.00000, n = 10
 * Output: 1024.00000
 *
 *
 * Example 2:
 *
 *
 * Input: x = 2.10000, n = 3
 * Output: 9.26100
 *
 *
 * Example 3:
 *
 *
 * Input: x = 2.00000, n = -2
 * Output: 0.25000
 * Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
 *
 *
 *
 * Constraints:
 *
 *
 * -100.0 < x < 100.0
 * -2^31 <= n <= 2^31-1
 * -10^4 <= x^n <= 10^4
 *
 *
 */

#include "misc.h"
#include <iostream>
using namespace std;
// @lc code=start

class Solution {
  public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;

        if (x == 1.)
            return 1.;
        if (x == -1.)
            return n % 2 ? -1. : 1.;

        double res = 1;
        if (n < 0) {
            for (auto i = n; i < 0; i++) {
                res = res / x;
                if (res == .0)
                    break;
            }
        } else {
            for (auto i = 0; i < n; i++) {
                res = res * x;
                if (res == .0)
                    break;
            }
        }
        return res;
    }
};

// @lc code=end

int main(int argc, char const *argv[]) {
    cout << Solution().myPow(2, -2147483648) << endl;
    return 0;
}
