/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 *
 * https://leetcode.com/problems/integer-to-roman/description/
 *
 * algorithms
 * Medium (57.31%)
 * Likes:    1777
 * Dislikes: 3176
 * Total Accepted:    491K
 * Total Submissions: 856.6K
 * Testcase Example:  "3"
 *
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D
 * and M.
 *
 *
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 *
 * For example, 2 is written as II in Roman numeral, just two one"s added
 * together. 12 is written as XII, which is simply X + II. The number 27 is
 * written as XXVII, which is XX + V + II.
 *
 * Roman numerals are usually written largest to smallest from left to right.
 * However, the numeral for four is not IIII. Instead, the number four is
 * written as IV. Because the one is before the five we subtract it making
 * four. The same principle applies to the number nine, which is written as IX.
 * There are six instances where subtraction is used:
 *
 *
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 *
 *
 * Given an integer, convert it to a roman numeral.
 *
 *
 * Example 1:
 *
 *
 * Input: num = 3
 * Output: "III"
 *
 *
 * Example 2:
 *
 *
 * Input: num = 4
 * Output: "IV"
 *
 *
 * Example 3:
 *
 *
 * Input: num = 9
 * Output: "IX"
 *
 *
 * Example 4:
 *
 *
 * Input: num = 58
 * Output: "LVIII"
 * Explanation: L = 50, V = 5, III = 3.
 *
 *
 * Example 5:
 *
 *
 * Input: num = 1994
 * Output: "MCMXCIV"
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= num <= 3999
 *
 *
 */

#include <string>
using namespace std;
// @lc code=start

class Solution {
  public:
    string intToRoman(int num) {
        return s[3][num / 1000 % 10] + s[2][num / 100 % 10] + s[1][num / 10 % 10] + s[0][num % 10];
    }

  private:
    string const s[4][10] = {
        {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
        {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
        {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
        {"", "M", "MM", "MMM"},
    };
};
// @lc code=end

/* My Solution */
// #include <utility>
// #include <vector>

// class Solution {
//   public:
//     string intToRoman(int num) {
//         string res;
//         for (auto &i : mapping) {
//             if (num >= i.first) {
//                 int times = num / i.first;
//                 for (auto j = 0; j < times; j++)
//                     res += i.second;
//                 num -= i.first * times;
//             }
//         }
//         return res;
//     }

//   private:
//     vector<pair<int, string>> const mapping = {make_pair(1000, "M"), make_pair(900, "CM"),
//         make_pair(500, "D"), make_pair(400, "CD"), make_pair(100, "C"), make_pair(90,
//         "XC"), make_pair(50, "L"), make_pair(40, "XL"), make_pair(10, "X"), make_pair(9,
//         "IX"), make_pair(5, "V"), make_pair(4, "IV"), make_pair(1, "I")};
// };