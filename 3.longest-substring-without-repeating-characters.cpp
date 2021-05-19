/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (31.69%)
 * Likes:    14447
 * Dislikes: 739
 * Total Accepted:    2.2M
 * Total Submissions: 6.9M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string s, find the length of the longest substring without repeating
 * characters.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * Notice that the answer must be a substring, "pwke" is a subsequence and not
 * a substring.
 *
 *
 * Example 4:
 *
 *
 * Input: s = ""
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= s.length <= 5 * 10^4
 * s consists of English letters, digits, symbols and spaces.
 *
 *
 */

// @lc code=start
class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        int maxLen       = 0;
        bool bitmap[256] = {0};

        for (int left = 0, right = 0; right < s.size(); right++) {
            if (bitmap[s[right]] == 0) {  // not exists
                bitmap[s[right]] = 1;
            } else {  // exists
                // cout << "Find at right = " << right << ", left is " << left;
                // cout << ", bitmap" << bitmap[97] << bitmap[98] << bitmap[99];

                for (; s[left] != s[right]; left++)
                    bitmap[s[left]] = 0;  // reset bitmap for those beteen old and new left
                left++;                   // left now is (index of same val as s[right]) + 1

                // cout << ", new left: " << left;
                // cout << ", bitmap" << bitmap[97] << bitmap[98] << bitmap[99] << endl;
            }
            maxLen = right - left + 1 > maxLen ? right - left + 1 : maxLen;  // 0a1b2a -> 2
        }
        return maxLen;
    }
};
// @lc code=end
