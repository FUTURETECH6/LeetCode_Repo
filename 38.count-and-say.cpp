/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Medium (46.71%)
 * Likes:    542
 * Dislikes: 1746
 * Total Accepted:    515.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is a sequence of digit strings defined by the
 * recursive formula:
 *
 *
 * countAndSay(1) = "1"
 * countAndSay(n) is the way you would "say" the digit string from
 * countAndSay(n-1), which is then converted into a different digit string.
 *
 *
 * To determine how you "say" a digit string, split it into the minimal number
 * of groups so that each group is a contiguous section all of the same
 * character. Then for each group, say the number of characters, then say the
 * character. To convert the saying into a digit string, replace the counts
 * with a number and concatenate every saying.
 *
 * For example, the saying and conversion for digit string "3322251":
 *
 * Given a positive integer n, return the n^th term of the count-and-say
 * sequence.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 1
 * Output: "1"
 * Explanation: This is the base case.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 4
 * Output: "1211"
 * Explanation:
 * countAndSay(1) = "1"
 * countAndSay(2) = say "1" = one 1 = "11"
 * countAndSay(3) = say "11" = two 1's = "21"
 * countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 30
 *
 *
 */
#include <iostream>
#include <string>
using namespace std;
// @lc code=start
class Solution {
  public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        auto old = countAndSay(n - 1) + '$';
        string result;
        auto first = old[0];
        auto count = 0;
        for (auto &i : old) {
            if (first != i) {
                result += std::to_string(count);
                result += first;
                first = i;
                count = 1;  // Here, not 0
            } else {
                count++;
            }
        }
        return result;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    for (auto i = 1; i <= 30; i++)
        cout << Solution().countAndSay(i) << endl;
    return 0;
}
