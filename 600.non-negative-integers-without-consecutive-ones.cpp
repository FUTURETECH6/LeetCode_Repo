/*
 * @lc app=leetcode id=600 lang=cpp
 *
 * [600] Non-negative Integers without Consecutive Ones
 *
 * https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/description/
 *
 * algorithms
 * Hard (38.69%)
 * Likes:    1061
 * Dislikes: 114
 * Total Accepted:    30.5K
 * Total Submissions: 78.7K
 * Testcase Example:  '5'
 *
 * Given a positive integer n, return the number of the integers in the range
 * [0, n] whose binary representations do not contain consecutive ones.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 5
 * Output: 5
 * Explanation:
 * Here are the non-negative integers <= 5 with their corresponding binary
 * representations:
 * 0 : 0
 * 1 : 1
 * 2 : 10
 * 3 : 11
 * 4 : 100
 * 5 : 101
 * Among them, only integer 3 disobeys the rule (two consecutive ones) and the
 * other 5 satisfy the rule.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1
 * Output: 2
 *
 *
 * Example 3:
 *
 *
 * Input: n = 2
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 10^9
 *
 *
 */

#include <iostream>
using namespace std;

// @lc code=start

#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>

class Solution {
  private:
    int bitWidth(int n) { return int(log2(n)) + 1; }
    //                                                                             0
    //                                                                             0
    // 11                                                                          1
    // 110 111                                                                     2
    // 1100 1101 1110 1111 | 10 + {11}                                             5
    // 11000 ... 11111(8) | 10 + {011 | 110 111}                                   11
    // 110000 ... 111111(16) | 10 + {0011 | 0110 0111 | 1100 1101 1110 1111 1011}  24
    int findConsecutive(const int n) {
        if (n < 3)
            return 0;

        int consecutive = 0;

        static auto count = vector<int>(2, 0);

        for (int i = 0b11; bitWidth(i << 1) <= bitWidth(n); i <<= 1) {  // {0b11, 0b110, 0b1100, ...}
            if (count.size() - 1 < bitWidth(i))
                count.push_back(accumulate(count.begin(), count.end() - 1, decltype(count)::value_type(0)) + pow(2, bitWidth(i) - 2));  // pow(2, bitNum(i)): |0b1100... ~ 0b1111...| = 0b100...
            consecutive += count[bitWidth(i)];
        }

        switch (n >> (bitWidth(n) - 2)) {
            case 0b11:
                consecutive += accumulate(count.begin(), count.begin() + bitWidth(n) - 1, decltype(count)::value_type(0))  // 10 part, complete
                               + (n - (0b11 << (bitWidth(n) - 2)) + 1);                                                    // 11 part, incomplete
                break;
            case 0b10: consecutive += findConsecutive(n - (0b10 << (bitWidth(n) - 1 - 1))); break;  // incomplete

            default: break;  // less than 0b10
        }
        return consecutive;
    }

  public:
    int findIntegers(const int n) { return n + 1 - findConsecutive(n); }
};
// @lc code=end
int main(int argc, char const *argv[]) {
    cout << Solution().findIntegers(5) << endl;          // 5
    cout << Solution().findIntegers(100000000) << endl;  // 514229
    cout << Solution().findIntegers(5641561) << endl;    // 75025
    cout << Solution().findIntegers(26) << endl;         // 13, 26=0b11010
    cout << Solution().findIntegers(536) << endl;        // 102, 536 = 0b1000011000
    cout << Solution().findIntegers(23) << endl;         // 13, 23 = 0b10111
    cout << Solution().findIntegers(21) << endl;         // 13, 21 = 0b10101

    return 0;
}
