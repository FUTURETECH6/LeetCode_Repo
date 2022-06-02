/*
 * @lc app=leetcode id=1291 lang=cpp
 *
 * [1291] Sequential Digits
 *
 * https://leetcode.com/problems/sequential-digits/description/
 *
 * algorithms
 * Medium (60.84%)
 * Likes:    1592
 * Dislikes: 98
 * Total Accepted:    75.9K
 * Total Submissions: 124.6K
 * Testcase Example:  '100\n300'
 *
 * An integer has sequential digits if and only if each digit in the number is
 * one more than the previous digit.
 *
 * Return a sorted list of all the integers in the range [low, high] inclusive
 * that have sequential digits.
 *
 *
 * Example 1:
 * Input: low = 100, high = 300
 * Output: [123,234]
 * Example 2:
 * Input: low = 1000, high = 13000
 * Output: [1234,2345,3456,4567,5678,6789,12345]
 *
 *
 * Constraints:
 *
 *
 * 10 <= low <= high <= 10^9
 *
 *
 */

#include "misc.h"
using namespace std;

// @lc code=start

#include <cmath>
#include <string>

class Solution {
  private:
    const string digits = "123456789";
    int digitWidth(int n) { return int(log10(n)) + 1; }

  public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;

        for (int len = digitWidth(low); len <= digitWidth(high); len++) {
            for (int j = 0; j + len < 10; j++) {
                int digit = stoi(digits.substr(j, len));
                if (digit < low)
                    continue;
                if (digit > high)
                    break;
                result.push_back(digit);
            }
        }

        return result;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    misc::printVec(Solution().sequentialDigits(100, 300));
    return 0;
}
