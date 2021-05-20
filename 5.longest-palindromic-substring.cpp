/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (30.79%)
 * Likes:    10853
 * Dislikes: 696
 * Total Accepted:    1.3M
 * Total Submissions: 4.2M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, return the longest palindromic substring in s.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "cbbd"
 * Output: "bb"
 *
 *
 * Example 3:
 *
 *
 * Input: s = "a"
 * Output: "a"
 *
 *
 * Example 4:
 *
 *
 * Input: s = "ac"
 * Output: "a"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 1000
 * s consist of only digits and English letters (lower-case and/or upper-case),
 *
 */

#include <iostream>
#include <string>
using namespace std;
// @lc code=start
#include <vector>

class Solution {

  public:
    string longestPalindrome(string s) {
        // Init Part
        string ss = "#";
        for (auto &i : s) {
            ss += i;
            ss += "#";
        }
        vector<int> p;
        p.resize(ss.size(), 0);

        // Main Part
        int id = 0, mx = 0;
        for (auto i = 1; i < ss.size(); i++) {
            // Set init p[i] quickly
            p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;

            // Expand p[i]
            while (i + p[i] < ss.size() && i - p[i] >= 0 && ss[i + p[i]] == ss[i - p[i]])
                p[i]++;

            // Enlarge mx if possible
            if (i + p[i] > mx) {
                mx = i + p[i];
                id = i;
            }
        }

        int maxI = 0, maxPi = 0;
        for (int i = 0; i < ss.size(); i++) {
            if (p[i] > maxPi) {
                maxPi = p[i];
                maxI  = i;
            }
        }
        // 01234567890
        // #0#1#2#3#4#
        // #a#b#c#b#d# 123, maxI=5, maxPi=4
        // #a#b#b#c#d# 12,  maxI=4, maxPi=3
        return s.substr(maxI / 2 - (maxPi - 1) / 2, maxPi - 1);
        // return s;
    }
};
// @lc code=end
