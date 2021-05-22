/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (40.10%)
 * Likes:    7529
 * Dislikes: 309
 * Total Accepted:    1.4M
 * Total Submissions: 3.6M
 * Testcase Example:  '"()"'
 *
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 *
 * An input string is valid if:
 *
 *
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: s = "()"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: s = "()[]{}"
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: s = "(]"
 * Output: false
 *
 *
 * Example 4:
 *
 *
 * Input: s = "([)]"
 * Output: false
 *
 *
 * Example 5:
 *
 *
 * Input: s = "{[]}"
 * Output: true
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * s consists of parentheses only '()[]{}'.
 *
 *
 */

#include <string>
using namespace std;
// @lc code=start
#include <stack>
#include <unordered_map>

class Solution {
  public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto &c : s)
            switch (c) {
                case '(':
                case '[':
                case '{': {
                    stk.push(c);
                    break;
                }
                case ')':
                case ']':
                case '}': {
                    if (stk.empty() || stk.top() != mapping[c])
                        return false;
                    else
                        stk.pop();
                    break;
                }
            }

        return stk.empty();
    }

  private:
    unordered_map<char, char> mapping = {{')', '('}, {']', '['}, {'}', '{'}};
};
// @lc code=end
