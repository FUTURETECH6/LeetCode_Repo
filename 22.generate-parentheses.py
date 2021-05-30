#
# @lc app=leetcode id=22 lang=python3
#
# [22] Generate Parentheses
#
# https://leetcode.com/problems/generate-parentheses/description/
#
# algorithms
# Medium (66.11%)
# Likes:    7968
# Dislikes: 336
# Total Accepted:    745.9K
# Total Submissions: 1.1M
# Testcase Example:  '3'
#
# Given n pairs of parentheses, write a function to generate all combinations
# of well-formed parentheses.
#
#
# Example 1:
# Input: n = 3
# Output: ["((()))","(()())","(())()","()(())","()()()"]
#           000111   001011   001101   010011   010101
# n = 2
# (()) ()()
# 0011 0101
#
# Example 2:
# Input: n = 1
# Output: ["()"]
#
#
# Constraints:
#
#
# 1 <= n <= 8
#
#
#

# @lc code=start

class Solution:
    def generateParenthesis(self, n):
        # p: string that being passed
        # left & right: '(' & ')' num not used
        def generate(p, left, right, parens=[]):
            # ensure left <= right
            if left != 0:
                generate(p + '(', left-1, right)
            if right > left:
                generate(p + ')', left, right-1)
            if right == 0:
                parens.append(p),
            return parens
        return generate('', n, n)

# @lc code=end
#     def generateParenthesis(self, n: int) -> List[str]:
#         ret = []

#         for i in range(1, 2 ** (2 * n - 1), 2):
#             flag = True
#             num = i
#             num_0 = 0
#             num_1 = 0
#             for _ in range(0, 2 * n):  # 从右往左 num_1 >= num_0
#                 if num % 2 == 1:
#                     num_1 += 1
#                 else:
#                     num_0 += 1

#                 if num_1 < num_0 or num_1 > n:
#                     flag = False
#                     break

#                 num >>= 1

#             if flag:
#                 num = i
#                 pair = ''
#                 for _ in range(0, 2 * n):
#                     pair += ')' if num % 2 == 1 else '('
#                     num >>= 1
#                 ret.append(pair[-1::-1])

#         return ret
