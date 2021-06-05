/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (27.55%)
 * Likes:    5794
 * Dislikes: 849
 * Total Accepted:    541.4K
 * Total Submissions: 2M
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement regular expression
 * matching with support for '.' and '*' where: 
 *
 *
 * '.' Matches any single character.​​​​
 * '*' Matches zero or more of the preceding element.
 *
 *
 * The matching should cover the entire input string (not partial).
 *
 *
 * Example 1:
 *
 *
 * Input: s = "aa", p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "aa", p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the preceding element, 'a'.
 * Therefore, by repeating 'a' once, it becomes "aa".
 *
 *
 * Example 3:
 *
 *
 * Input: s = "ab", p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 *
 *
 * Example 4:
 *
 *
 * Input: s = "aab", p = "c*a*b"
 * Output: true
 * Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore,
 * it matches "aab".
 *
 *
 * Example 5:
 *
 *
 * Input: s = "mississippi", p = "mis*is*p*."
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= s.length <= 20
 * 0 <= p.length <= 30
 * s contains only lowercase English letters.
 * p contains only lowercase English letters, '.', and '*'.
 * It is guaranteed for each appearance of the character '*', there will be a
 * previous valid character to match.
 *
 *
 */

#include <iostream>
#include <string>
using namespace std;
// @lc code=start
class Solution {
  public:
    bool isMatch(string s, string p) {
        if (!p.size())  // |p| == 0
            return !s.size();
        else if (!s.size()) {    // |s| == 0 && |p| > 0
            switch (p.size()) {  // |p| > 0
                case 1: return false;
                case 2: return p[1] == '*';
                default: return p[1] == '*' && isMatch(s, p.substr(2, p.size() - 2));
            }
        } else {  // |s| > 0 && |p| > 0
            bool firstMatch = s[0] == p[0] || p[0] == '.';

            if (p.size() >= 2 && p[1] == '*')                                // |s| > 0 && p[0:2] == x*
                return isMatch(s, p.substr(2, p.size() - 2)) ||              // * = 0
                       firstMatch && isMatch(s.substr(1, s.size() - 1), p);  // * used, match next
            else                                                             // |s| > 0 && normal p
                return firstMatch && isMatch(s.substr(1, s.size() - 1), p.substr(1, p.size() - 1));
        }
    }
};
// @lc code=end
