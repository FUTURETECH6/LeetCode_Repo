/*
 * @lc app=leetcode id=1371 lang=cpp
 *
 * [1371] Find the Longest Substring Containing Vowels in Even Counts
 *
 * https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/
 *
 * algorithms
 * Medium (62.40%)
 * Likes:    1065
 * Dislikes: 40
 * Total Accepted:    17.9K
 * Total Submissions: 28.7K
 * Testcase Example:  '"eleetminicoworoep"'
 *
 * Given the string s, return the size of the longest substring containing each
 * vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must
 * appear an even number of times.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "eleetminicoworoep"
 * Output: 13
 * Explanation: The longest substring is "leetminicowor" which contains two
 * each of the vowels: e, i and o and zero of the vowels: a and u.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "leetcodeisgreat"
 * Output: 5
 * Explanation: The longest substring is "leetc" which contains two e's.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "bcbcbc"
 * Output: 6
 * Explanation: In this case, the given string "bcbcbc" is the longest because
 * all vowels: a, e, i, o and u appear zero times.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 5 x 10^5
 * s contains only lowercase English letters.
 *
 *
 */

#include "misc.h"
#include <string>
#include <vector>
using namespace std;
// @lc code=start

#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>

class Solution {
  private:
    inline static bool isVowel(char c) {
        static const set<char> vowel = {'a', 'e', 'i', 'o', 'u'};
        return vowel.find(c) != vowel.end();
    }

  public:
    // int findTheLongestSubstring(string s) {
    //     unordered_map<char, int> m{{'x', -1}};
    //     int res             = 0;
    //     map<char, bool> cur = {{'x', true}, {'a', true}, {'e', true}, {'i', true}, {'o', true}, {'u', true}};
    //     for (int i = 0; i < s.length(); i++) {
    //         // cur ^= 1 << string("aeiou").find(s[i]) + 1 >> 1;
    //         if (isVowel(s[i]))
    //             cur[s[i]] = !cur[s[i]];
    //         else
    //             cur['x'] = !cur['x'];
    //
    //         if (!m.count(cur))
    //             m[cur] = i;
    //         res = max(res, i - m[cur]);
    //     }
    //     return res;
    // }

    int findTheLongestSubstring(string s) {
        map<int, int> m{{0, -1}};
        int res = 0, n = s.length(), cur = 0;
        for (int i = 0; i < n; i++) {
            if (isVowel(s[i]))
                cur ^= 1 << string("aeiou").find(s[i]);
            else
                cur ^= 0;
            if (m.count(cur) == 0)
                m[cur] = i;
            res = max(res, i - m[cur]);
        }
        return res;
    }
};

// @lc code=end

int main(int argc, char const *argv[]) {
    cout << Solution().findTheLongestSubstring("eleetminicoworoep") << endl;
    return 0;
}

// #include <map>
// #include <set>

// class Solution {
//   private:
//     inline static int max(int a, int b) { return a > b ? a : b; }
//     inline static bool isVowel(char c) {
//         static const set<char> vowel = {'a', 'e', 'i', 'o', 'u'};
//         return vowel.contains(c);
//     }
//     inline static bool passCheck(map<char, bool> &m) {
//         for (auto &i : m)
//             if (i.second)
//                 return false;
//         return true;
//     }

//     int foo(string s, map<char, bool> m) {
//         if (passCheck(m))
//             return s.size();
//         if (s.size() == 0)
//             return 0;

//         if (isVowel(s.front()) && m[s.front()] == false && isVowel(s.back()) && m[s.back()] == false) {
//             m[s.front()] = !m[s.front()];
//             m[s.back()]  = !m[s.back()];
//             return foo(s.substr(1, s.size() - 2), m);
//         } else if (isVowel(s.front()) && m[s.front()] == false) {
//             m[s.front()] = !m[s.front()];
//             return foo(s.substr(1, s.size() - 1), m);
//         } else if (isVowel(s.back()) && m[s.back()] == false) {
//             m[s.back()] = !m[s.back()];
//             return foo(s.substr(0, s.size() - 1), m);
//         } else {
//             int a, b;
//             if (isVowel(s.front()))
//                 m[s.front()] = !m[s.front()];
//             a = foo(s.substr(1, s.size() - 1), m);

//             if (isVowel(s.back()))
//                 m[s.back()] = !m[s.back()];
//             b = foo(s.substr(0, s.size() - 1), m);

//             return max(a, b);
//         }
//     }

//   public:
//     int findTheLongestSubstring(string s) {
//         map<char, bool> m = {{'a', true}, {'e', true}, {'i', true}, {'o', true}, {'u', true}};

//         for (auto &i : s)
//             if (m.contains(i))
//                 m[i] = !m[i];

//         return foo(s, m);
//     }
// };