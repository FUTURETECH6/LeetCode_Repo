#
# @lc app=leetcode id=30 lang=python3
#
# [30] Substring with Concatenation of All Words
#
# https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
#
# algorithms
# Hard (26.58%)
# Likes:    1282
# Dislikes: 1496
# Total Accepted:    208.7K
# Total Submissions: 784.9K
# Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
#
# You are given a string s and an array of strings words of the same length.
# Return all starting indices of substring(s) in s that is a concatenation of
# each word in words exactly once, in any order, and without any intervening
# characters.
#
# You can return the answer in any order.
#
#
# Example 1:
#
#
# Input: s = "barfoothefoobarman", words = ["foo","bar"]
# Output: [0,9]
# Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar"
# respectively.
# The output order does not matter, returning [9,0] is fine too.
#
#
# Example 2:
#
#
# Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
# Output: []
#
#
# Example 3:
#
#
# Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
# Output: [6,9,12]
#
#
#
# Constraints:
#
#
# 1 <= s.length <= 10^4
# s consists of lower-case English letters.
# 1 <= words.length <= 5000
# 1 <= words[i].length <= 30
# words[i] consists of lower-case English letters.
#
#
#

# @lc code=start

class Solution:
    def findSubstring(self, s: str, words):
        result = []
        wordLen = len(words[0])
        targetLen = wordLen * len(words)

        hotDict = dict()
        for word in words:
            if word in hotDict.keys():
                hotDict[word] += 1
            else:
                hotDict[word] = 1  # const after this

        for fstInd in range(0, len(s) - targetLen + 1):
            tmpDict = hotDict.copy()
            for scnInd in range(fstInd, fstInd + targetLen, wordLen):
                tmpWord = s[scnInd:scnInd+wordLen]
                if tmpWord in hotDict.keys() and tmpDict[tmpWord] > 0:
                    tmpDict[tmpWord] -= 1
                else:  # Not match
                    break
            else:  # No break, so this is a match
                result.append(fstInd)

        return result


# @lc code=end

# print(Solution().findSubstring(s, words))
'''
一个重要条件是 You are given a string s and an array of strings words of the **same length**.
'''
