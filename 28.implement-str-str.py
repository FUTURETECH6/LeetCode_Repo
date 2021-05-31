#
# @lc app=leetcode id=28 lang=python3
#
# [28] Implement strStr()
#
# https://leetcode.com/problems/implement-strstr/description/
#
# algorithms
# Easy (35.54%)
# Likes:    2406
# Dislikes: 2434
# Total Accepted:    892.6K
# Total Submissions: 2.5M
# Testcase Example:  '"hello"\n"ll"'
#
# Implement strStr().
#
# Return the index of the first occurrence of needle in haystack, or -1 if
# needle is not part of haystack.
#
# Clarification:
#
# What should we return when needle is an empty string? This is a great
# question to ask during an interview.
#
# For the purpose of this problem, we will return 0 when needle is an empty
# string. This is consistent to C's strstr() and Java's indexOf().
#
#
# Example 1:
# Input: haystack = "hello", needle = "ll"
# Output: 2
# Example 2:
# Input: haystack = "aaaaa", needle = "bba"
# Output: -1
# Example 3:
# Input: haystack = "", needle = ""
# Output: 0
#
#
# Constraints:
#
#
# 0 <= haystack.length, needle.length <= 5 * 10^4
# haystack and needle consist of only lower-case English characters.
#
#
#

# @lc code=start
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        for i in range(len(haystack) - len(needle) + 1):
            if haystack[i:i+len(needle)] == needle:
                return i
        return -1
# @lc code=end


print(Solution().strStr('Hell', 'll'))
