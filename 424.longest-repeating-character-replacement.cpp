/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 *
 * https://leetcode.com/problems/longest-repeating-character-replacement/description/
 *
 * algorithms
 * Medium (50.64%)
 * Likes:    4221
 * Dislikes: 170
 * Total Accepted:    208.4K
 * Total Submissions: 410.4K
 * Testcase Example:  '"ABAB"\n2'
 *
 * You are given a string s and an integer k. You can choose any character of
 * the string and change it to any other uppercase English character. You can
 * perform this operation at most k times.
 *
 * Return the length of the longest substring containing the same letter you
 * can get after performing the above operations.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "ABAB", k = 2
 * Output: 4
 * Explanation: Replace the two 'A's with two 'B's or vice versa.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "AABABBA", k = 1
 * Output: 4
 * Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
 * The substring "BBBB" has the longest repeating letters, which is 4.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s consists of only uppercase English letters.
 * 0 <= k <= s.length
 *
 *
 */

#include <iostream>
#include <string>
using namespace std;

// @lc code=start

#include <algorithm>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution {
  public:
    int characterReplacement(const string s, const int k) {
        unordered_map<char, vector<pair<size_t, size_t>>> locMap;

        auto lastC       = s[0];
        size_t tmp_begin = 0;
        for (size_t i = 1; i < s.size(); i++) {
            if (s[i] != lastC) {
                if (locMap.count(lastC) == 0)
                    locMap[lastC].push_back({0, 0});  // important, add {0,0}
                locMap[lastC].push_back({tmp_begin, i});
                tmp_begin = i;
                lastC     = s[i];
            }
        }
        if (locMap.count(lastC) == 0)
            locMap[lastC].push_back({0, 0});  // important, in case "AAAB"
        locMap[lastC].push_back({tmp_begin, s.size()});

        for (auto &[c, vec] : locMap) {
            vec.push_back({s.size(), s.size()});  // important, add {n,n}
        }

        int maxLength = 0;

        for (auto &[c, vec] : locMap) {
            auto remainK       = k;
            size_t begin_slice = 0;

            for (size_t i_slice = 1; i_slice < vec.size(); i_slice++) {
                remainK -= vec[i_slice].first - vec[i_slice - 1].second;

                while (remainK < 0) {
                    remainK += vec[begin_slice + 1].first - vec[begin_slice].second;
                    begin_slice++;
                }

                if (maxLength < vec[i_slice].second - vec[begin_slice].first + remainK)
                    maxLength = vec[i_slice].second - vec[begin_slice].first + remainK;
            }
        }

        return min(maxLength, (int)s.size());  // in case '"AAAA"\n2'
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    cout << Solution().characterReplacement("KRSCDCSONAJNHLBMDQGIFCPEKPOHQIHLTDIQGEKLRLCQNBOHNDQGHJPNDQPERNFSSSRDEQLFPCCCARFMDLHADJADAGNNSBNCJQOF", 4) << endl;  // 7
    return 0;
}
