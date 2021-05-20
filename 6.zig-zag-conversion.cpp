/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (38.53%)
 * Likes:    2380
 * Dislikes: 5876
 * Total Accepted:    574.7K
 * Total Submissions: 1.5M
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 *
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 *
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 *
 *
 * string convert(string s, int numRows);
 *
 *
 *
 * Example 1:
 *
 *             01234567890123
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 * 0     4     8    12
 * 1  3  5  7  9 11 13
 * 2     6    10
 *
 * Example 2:
 *
 *             01234567890123
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 *
 * 0        6       12
 * 1     5  7    11 13
 * 2  4     8 10
 * 3        9
 *
 * Example 3:
 *
 *
 * Input: s = "A", numRows = 1
 * Output: "A"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 1000
 * s consists of English letters (lower-case and upper-case), ',' and '.'.
 * 1 <= numRows <= 1000
 *
 *
 */

#include <string>
using namespace std;
// @lc code=start
class Solution {
  public:
    string convert(string s, int numRows) {
        string result = "";

        int const strLen = s.length();
        int const step   = (numRows - 1) << 1;  // 0 iff numRows == 1

        // First line
        for (int base = 0; base < strLen; base += step ? step : 1)
            result += s[base];

        // Middle Lines
        if (numRows >= 3)
            for (int i = 1; i < step / 2; i++)
                for (int base = 0; base < strLen; base += step)
                    if (base + i < strLen) {
                        result += s[base + i];

                        // Second `if` unnecessary if first `if` unsatisfied
                        if (base + step - i < strLen)
                            result += s[base + step - i];
                    }

        // Last line
        if (numRows >= 2)
            for (int base = 0; base < strLen; base += step)
                if (base + step / 2 < strLen)
                    result += s[base + step / 2];

        return result;
    }
};
// @lc code=end
