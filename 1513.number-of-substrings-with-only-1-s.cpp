/*
 * @lc app=leetcode id=1513 lang=cpp
 *
 * [1513] Number of Substrings With Only 1s
 *
 * https://leetcode.com/problems/number-of-substrings-with-only-1s/description/
 *
 * algorithms
 * Medium (44.09%)
 * Likes:    497
 * Dislikes: 22
 * Total Accepted:    28.6K
 * Total Submissions: 64.8K
 * Testcase Example:  '"0110111"'
 *
 * Given a binary string s, return the number of substrings with all characters
 * 1's. Since the answer may be too large, return it modulo 10^9 + 7.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "0110111"
 * Output: 9
 * Explanation: There are 9 substring in total with only 1's characters.
 * "1" -> 5 times.
 * "11" -> 3 times.
 * "111" -> 1 time.
 *
 * Example 2:
 *
 *
 * Input: s = "101"
 * Output: 2
 * Explanation: Substring "1" is shown 2 times in s.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "111111"
 * Output: 21
 * Explanation: Each substring contains only 1's characters.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s[i] is either '0' or '1'.
 *
 *
 */

#include "misc.h"
#include <iostream>
#include <string>
using namespace std;

// @lc code=start

#include <map>

class Solution {
  private:
    const static int modulo;

    map<int, int> dict = {{1, 1}};

    // [1, 1], [2, 3], [3, 6], ..., [n, $\Sigma_{i=1}^{n} (n-i)$]
    int get(int n) {
        if (dict.find(n) != dict.end()) {
            return dict[n];
        }
        dict[n] = (get(n - 1) + n) % modulo;
        return dict[n];
    }

  public:
    int numSub(string s) {
        long result = 0, len = 0;
        s += '0';
        for (auto &i : s) {
            if (i == '1') {
                len++;
            } else if (len != 0) {  // i!='1' && len!=0
                result = (result + get(len)) % modulo;
                len    = 0;
            }
        }

        return result;
    }
};

const int Solution::modulo = 1e9 + 7;

// @lc code=end

int main(int argc, char const *argv[]) {
    // cout << Solution().numSub("11011010110110111110") << endl;
    // cout << Solution().numSub("111111") << endl;  // 21
    // cout << Solution().numSub("11101") << endl;  // 7
    // cout << Solution().numSub("0110111") << endl;  // 9

    // unsigned a = (1e9);
    cout << 10e9l << endl;
    // cout << 1053058879l % a << endl;
    return 0;
}
