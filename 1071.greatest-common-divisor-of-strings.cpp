/*
 * @lc app=leetcode id=1071 lang=cpp
 *
 * [1071] Greatest Common Divisor of Strings
 *
 * https://leetcode.com/problems/greatest-common-divisor-of-strings/description/
 *
 * algorithms
 * Easy (51.58%)
 * Likes:    1252
 * Dislikes: 251
 * Total Accepted:    70K
 * Total Submissions: 135.8K
 * Testcase Example:  '"ABCABC"\n"ABC"'
 *
 * For two strings s and t, we say "t divides s" if and only if s = t + ... + t
 * (i.e., t is concatenated with itself one or more times).
 *
 * Given two strings str1 and str2, return the largest string x such that x
 * divides both str1 and str2.
 *
 *
 * Example 1:
 *
 *
 * Input: str1 = "ABCABC", str2 = "ABC"
 * Output: "ABC"
 *
 *
 * Example 2:
 *
 *
 * Input: str1 = "ABABAB", str2 = "ABAB"
 * Output: "AB"
 *
 *
 * Example 3:
 *
 *
 * Input: str1 = "LEET", str2 = "CODE"
 * Output: ""
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= str1.length, str2.length <= 1000
 * str1 and str2 consist of English uppercase letters.
 *
 *
 */

#include "misc.h"
#include <string>
using namespace std;

// @lc code=start

class Solution {
  private:
    bool divide(string t, string s) {
        if (s.size() % t.size() != 0)
            return false;
        for (int i = 0; i < s.size() / t.size(); i++) {
            if (t != s.substr(i * t.size(), t.size()))
                return false;
        }
        return true;
    }

  public:
    string gcdOfStrings(string str1, string str2) {
        string &str_short = str1.size() < str2.size() ? str1 : str2;
        string &str_long  = str1.size() < str2.size() ? str2 : str1;

        for (int i = 1; i <= str_short.size(); i++) {
            if (str_short.size() % i != 0)
                continue;
            int len      = str_short.size() / i;
            auto pattern = str_short.substr(0, len);
            if (divide(pattern, str_short) && divide(pattern, str_long))
                return pattern;
        }
        return "";
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    // cout << "\"" << Solution().gcdOfStrings("ABCABC", "ABCABCABC") << "\"" << endl;
    cout << "\"" << Solution().gcdOfStrings("LEET", "CODE") << "\"" << endl;
    return 0;
}
