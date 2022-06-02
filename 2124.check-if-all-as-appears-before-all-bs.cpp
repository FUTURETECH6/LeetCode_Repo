/*
 * @lc app=leetcode id=2124 lang=cpp
 *
 * [2124] Check if All A's Appears Before All B's
 *
 * https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/description/
 *
 * algorithms
 * Easy (72.64%)
 * Likes:    313
 * Dislikes: 5
 * Total Accepted:    30.9K
 * Total Submissions: 42.6K
 * Testcase Example:  '"aaabbb"'
 *
 * Given a string s consisting of only the characters 'a' and 'b', return true
 * if every 'a' appears before every 'b' in the string. Otherwise, return
 * false.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "aaabbb"
 * Output: true
 * Explanation:
 * The 'a's are at indices 0, 1, and 2, while the 'b's are at indices 3, 4, and
 * 5.
 * Hence, every 'a' appears before every 'b' and we return true.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "abab"
 * Output: false
 * Explanation:
 * There is an 'a' at index 2 and a 'b' at index 1.
 * Hence, not every 'a' appears before every 'b' and we return false.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "bbb"
 * Output: true
 * Explanation:
 * There are no 'a's, hence, every 'a' appears before every 'b' and we return
 * true.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 100
 * s[i] is either 'a' or 'b'.
 *
 *
 */

#include <iostream>
#include <string>
#define DEBUG
using namespace std;

// @lc code=start

#include <algorithm>

class Solution {
  public:
    bool checkString(string s) {
#ifdef DEBUG
        auto last_a = s.rend() - 1 - find(s.rbegin(), s.rend(), 'a'), first_b = find(s.begin(), s.end(), 'b') - s.begin();
        cout << last_a << " " << first_b << endl;
#endif
        return s.rend() - 1 - find(s.rbegin(), s.rend(), 'a') < find(s.begin(), s.end(), 'b') - s.begin();
    }
};
// @lc code=end
int main(int argc, char const *argv[]) {
    cout << Solution().checkString("abab") << endl;
    return 0;
}
