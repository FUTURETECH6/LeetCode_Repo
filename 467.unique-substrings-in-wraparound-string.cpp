/*
 * @lc app=leetcode id=467 lang=cpp
 *
 * [467] Unique Substrings in Wraparound String
 *
 * https://leetcode.com/problems/unique-substrings-in-wraparound-string/description/
 *
 * algorithms
 * Medium (37.39%)
 * Likes:    1052
 * Dislikes: 134
 * Total Accepted:    34.5K
 * Total Submissions: 92.1K
 * Testcase Example:  '"a"'
 *
 * We define the string s to be the infinite wraparound string of
 * "abcdefghijklmnopqrstuvwxyz", so s will look like this:
 *
 *
 * "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
 *
 *
 * Given a string p, return the number of unique non-empty substrings of p are
 * present in s.
 *
 *
 * Example 1:
 *
 *
 * Input: p = "a"
 * Output: 1
 * Explanation: Only the substring "a" of p is in s.
 *
 *
 * Example 2:
 *
 *
 * Input: p = "cac"
 * Output: 2
 * Explanation: There are two substrings ("a", "c") of p in s.
 *
 *
 * Example 3:
 *
 *
 * Input: p = "zab"
 * Output: 6
 * Explanation: There are six substrings ("z", "a", "b", "za", "ab", and "zab")
 * of p in s.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= p.length <= 10^5
 * p consists of lowercase English letters.
 *
 *
 */

#include "misc.h"
#include <string>
using namespace std;

// @lc code=start

#include <numeric>

class Solution {
  private:
    char nextChar(char ch) { return ch == 'z' ? 'a' : ch + 1; }

  public:
    int findSubstringInWraproundString(string p) {
        int n = p.size();
        vector<int> count(26, 0);  // count[i]记录以i+'a'借尾的substr个数，例如，以g结尾的的有fg, efg, defg三个，count['d' - 'a']就是3
        int max_len = 0;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && p[i] == nextChar(p[i - 1])) {
                max_len++;
            } else {
                max_len = 1;
            }
            count[p[i] - 'a'] = max(count[p[i] - 'a'], max_len);
        }

        return accumulate(count.begin(), count.end(), decltype(count)::value_type(0));
    }
};

// @lc code=end

int main(int argc, char const *argv[]) {
    Solution().findSubstringInWraproundString("zab");
    return 0;
}
