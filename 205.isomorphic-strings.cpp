/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 *
 * https://leetcode.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (42.00%)
 * Likes:    3470
 * Dislikes: 642
 * Total Accepted:    490.9K
 * Total Submissions: 1.2M
 * Testcase Example:  '"egg"\n"add"'
 *
 * Given two strings s and t, determine if they are isomorphic.
 *
 * Two strings s and t are isomorphic if the characters in s can be replaced to
 * get t.
 *
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character, but a character may map to itself.
 *
 *
 * Example 1:
 * Input: s = "egg", t = "add"
 * Output: true
 * Example 2:
 * Input: s = "foo", t = "bar"
 * Output: false
 * Example 3:
 * Input: s = "paper", t = "title"
 * Output: true
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 5 * 10^4
 * t.length == s.length
 * s and t consist of any valid ascii character.
 *
 *
 */

#include <iostream>
#include <string>
using namespace std;

// @lc code=start

#include <unordered_map>

class Solution {
  public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;

        unordered_map<char, char> replace;
        for (unsigned i = 0; i < s.size(); i++) {
            if (replace.count(s[i])) {
                if (replace[s[i]] != t[i])
                    return false;
            } else {
                for (auto &[a, b] : replace) {
                    if (b == t[i])  // No two characters may map to the same character '
                        return false;
                }
                replace[s[i]] = t[i];
            }
        }

        return true;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    cout << Solution().isIsomorphic("paper", "title") << endl;        // 1
    cout << Solution().isIsomorphic("badc", "baba") << endl;          // 0
    cout << Solution().isIsomorphic("bbbaaaba", "aaabbbba") << endl;  // 0
    return 0;
}
