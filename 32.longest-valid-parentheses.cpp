/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (30.04%)
 * Likes:    5329
 * Dislikes: 193
 * Total Accepted:    381.8K
 * Total Submissions: 1.3M
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()".
 *
 *
 * Example 2:
 *
 *
 * Input: s = ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()".
 *
 *
 * Example 3:
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
 * 0 <= s.length <= 3 * 10^4
 * s[i] is '(', or ')'.
 *
 *
 */
#include <string>
using namespace std;
// @lc code=start
#include <stack>

class Solution {
  public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int longest = 0;
        for (auto i = 0; i < s.size(); i++)
            switch (s[i]) {
                case '(': stk.push(i); break;
                case ')':
                    stk.pop();
                    if (stk.empty())
                        stk.push(i);  // as leftest's prev one
                    else
                        longest = i - stk.top() > longest ? i - stk.top() : longest;
                    break;
            }

        return longest;
    }
};
// @lc code=end

#include <iostream>
int main(int argc, char const *argv[]) {
    cout << Solution().longestValidParentheses("())((())");
    return 0;
}
