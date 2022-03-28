/*
 * @lc app=leetcode id=1190 lang=cpp
 *
 * [1190] Reverse Substrings Between Each Pair of Parentheses
 *
 * https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/
 *
 * algorithms
 * Medium (65.64%)
 * Likes:    1247
 * Dislikes: 34
 * Total Accepted:    47K
 * Total Submissions: 71.6K
 * Testcase Example:  '"(abcd)"'
 *
 * You are given a string s that consists of lower case English letters and
 * brackets.
 *
 * Reverse the strings in each pair of matching parentheses, starting from the
 * innermost one.
 *
 * Your result should not contain any brackets.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "(abcd)"
 * Output: "dcba"
 *
 *
 * Example 2:
 *
 *
 * Input: s = "(u(love)i)"
 * Output: "iloveu"
 * Explanation: The substring "love" is reversed first, then the whole string
 * is reversed.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "(ed(et(oc))el)"
 * Output: "leetcode"
 * Explanation: First, we reverse the substring "oc", then "etco", and finally,
 * the whole string.
 *
 *
 * Input: s = "(ed(et(oc)zx)el)"
 * Output: "leetcozxde"
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 2000
 * s only contains lower case English characters and parentheses.
 * It is guaranteed that all parentheses are balanced.
 *
 *
 */

#include "misc.h"
#include <iostream>
#include <string>
using namespace std;

// @lc code=start

#include <algorithm>
#include <iterator>
#include <list>

class Solution {
  public:
    string reverseParentheses(string s) {
        list<char> char_list;
        copy(s.begin(), s.end(), back_inserter(char_list));

        while (find(char_list.begin(), char_list.end(), '(') != char_list.end()) {
            auto r = find(char_list.begin(), char_list.end(), ')'), l = prev(find(make_reverse_iterator(r), char_list.rend(), '(').base());
            if (next(l) != r) {
                reverse(next(l), r);
            }
            char_list.erase(r);
            char_list.erase(l);
        }

        s.clear();
        copy(char_list.begin(), char_list.end(), back_inserter(s));
        return s;
    }
};

// @lc code=end

int main(int argc, char const *argv[]) {
    // string a = "(ed(et(oc))el)";
    // string a = "(ed(et(oc)zx)el)";
    // string a = "(u(love)i)";
    // string a = "(abcd)";
    string a = "a(bcdefghijkl(mno)p)q";
    cout << Solution().reverseParentheses(a) << endl;
    return 0;
}

// string reverseParentheses(const string s) {
//     if (find(s.begin(), s.end(), '(') == s.end())
//         return s;

//     list<char> list_l, list_r;
//     unsigned l = find(s.begin(), s.end(), '(') - s.begin(), r = s.rend() - 1 - find(s.rbegin(), s.rend(), ')');
//     for (int i = 0; i < count(s.begin(), s.end(), '('); i++) {
//         if (i == count(s.begin(), s.end(), '(') - 1) {  // innermost one

//             if (i % 2 == 1)  // don't switch
//                 for (l++; s[l] != ')';)
//                     list_l.push_back(s[l++]);
//             else  // switch
//                 for (l++; s[l] != ')';)
//                     list_r.push_front(s[l++]);
//         } else if (i % 2 == 1) {  // don't switch
//             l++;
//             r--;

//             for (; s[l] != '(';)
//                 list_l.push_back(s[l++]);
//             for (; s[r] != ')';)
//                 list_r.push_front(s[r--]);
//         } else {  // switch
//             l++;
//             r--;

//             string tmp_l, tmp_r;
//             for (; s[l] != '(';)
//                 tmp_r += s[l++];
//             reverse(tmp_r.begin(), tmp_r.end());
//             for (; s[r] != ')';)
//                 tmp_l += s[r--];

//             copy(tmp_l.begin(), tmp_l.end(), back_inserter(list_l));
//             copy(tmp_r.rbegin(), tmp_r.rend(), front_inserter(list_r));
//         }
//     }
//     string result;
//     copy(s.begin(), find(s.begin(), s.end(), '('), back_inserter(result));
//     copy(list_l.begin(), list_l.end(), back_inserter(result));
//     copy(list_r.begin(), list_r.end(), back_inserter(result));
//     copy(s.begin() + (s.rend() - find(s.rbegin(), s.rend(), ')')), s.end(), back_inserter(result));
//     return result;
// }