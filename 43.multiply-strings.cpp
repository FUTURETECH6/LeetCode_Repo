/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (35.80%)
 * Likes:    2959
 * Dislikes: 1173
 * Total Accepted:    401.2K
 * Total Submissions: 1.1M
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 *
 * Note: You must not use any built-in BigInteger library or convert the inputs
 * to integer directly.
 *
 *
 * Example 1:
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * Example 2:
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 *
 *
 * Constraints:
 *
 *
 * 1 <= num1.length, num2.length <= 200
 * num1 and num2 consist of digits only.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 *
 *
 */

#include "misc.h"
#include <iostream>
#include <string>
using namespace std;
// @lc code=start
#include <vector>

class Solution {
  public:
    string multiply(string num1, string num2) {
        auto ary1 = vector<int>(num1.size()), ary2 = vector<int>(num2.size());
        for (int i = 0; i < num1.size(); i++)
            ary1[i] = num1[num1.size() - 1 - i] - '0';
        for (int i = 0; i < num2.size(); i++)
            ary2[i] = num2[num2.size() - 1 - i] - '0';

        auto result = vector<int>(num1.size() + num2.size());
        for (int i = 0; i < num1.size(); i++) {
            for (int j = 0; j < num2.size(); j++)
                result[i + j] += ary1[i] * ary2[j];
            // order
            for (int j = 0; j < result.size() - 1; j++) {
                result[j + 1] += result[j] / 10;
                result[j] %= 10;
            }
        }
        string resultStr;
        for (auto &i : result)
            resultStr = char(i + '0') + resultStr;
        resultStr = resultStr.erase(
            0, min(resultStr.find_first_not_of('0'),
                   resultStr.size() - 1));  // use `size - 1` to leave at least a '0'

        return resultStr;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    cout << Solution().multiply("1234", "23") << endl;
    return 0;
}
