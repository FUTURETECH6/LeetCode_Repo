#
# @lc app=leetcode id=17 lang=python3
#
# [17] Letter Combinations of a Phone Number
#
# https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
#
# algorithms
# Medium (50.23%)
# Likes:    6106
# Dislikes: 528
# Total Accepted:    843.8K
# Total Submissions: 1.7M
# Testcase Example:  '"23"'
#
# Given a string containing digits from 2-9 inclusive, return all possible
# letter combinations that the number could represent. Return the answer in any
# order.
#
# A mapping of digit to letters (just like on the telephone buttons) is given
# below. Note that 1 does not map to any letters.
#
#
#
#
# Example 1:
#
#
# Input: digits = "23"
# Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
#
#
# Example 2:
#
#
# Input: digits = ""
# Output: []
#
#
# Example 3:
#
#
# Input: digits = "2"
# Output: ["a","b","c"]
#
#
#
# Constraints:
#
#
# 0 <= digits.length <= 4
# digits[i] is a digit in the range ['2', '9'].
#
#
#

# @lc code=start
class Solution:
    mapping = {
        '1': None,
        '2': ['a', 'b', 'c'],
        '3': ['d', 'e', 'f'],
        '4': ['g', 'h', 'i'],
        '5': ['j', 'k', 'l'],
        '6': ['m', 'n', 'o'],
        '7': ['p', 'q', 'r', 's'],
        '8': ['t', 'u', 'v'],
        '9': ['w', 'x', 'y', 'z']
    }

    def letterCombinations(self, digits: str) -> List[str]:
        return self.addAlpha([''], digits) if len(digits) else []

    def addAlpha(self, array: List, digits: str) -> List[str]:
        res = []
        for original in array:
            for alpha in self.mapping[digits[0]]:
                res.append(original + alpha)

        return self.addAlpha(res, digits[1:]) if len(digits) > 1 else res
# @lc code=end
