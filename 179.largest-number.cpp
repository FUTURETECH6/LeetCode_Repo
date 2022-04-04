/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 *
 * https://leetcode.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (32.71%)
 * Likes:    4690
 * Dislikes: 398
 * Total Accepted:    309.1K
 * Total Submissions: 943.3K
 * Testcase Example:  '[10,2]'
 *
 * Given a list of non-negative integers nums, arrange them such that they form
 * the largest number and return it.
 *
 * Since the result may be very large, so you need to return a string instead
 * of an integer.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [10,2]
 * Output: "210"
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [3,30,34,5,9]
 * Output: "9534330"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 10^9
 *
 *
 */

#include "misc.h"
#include <string>
#include <vector>
using namespace std;

// @lc code=start

#include <algorithm>
#include <numeric>

/*
345
34
343

345 34 343
*/

class Solution {
  public:
    string largestNumber(vector<int> &nums) {
        vector<string> ss;
        transform(nums.begin(), nums.end(), std::back_inserter(ss), [](const int &i) { return to_string(i); });

        sort(ss.begin(), ss.end(), [](string &a, string &b) { return a + b > b + a; });
        // misc::printVec(ss);

        if (ss[0].front() == '0')
            return "0";
        else
            return accumulate(ss.begin(), ss.end(), string());
    }
};

// @lc code=end

int main(int argc, char const *argv[]) {
    vector<int> a = {3, 30, 34, 5, 9};  // 9 5 34 3 30
    // vector<int> a = {111311, 1113};  // 1113 111311
    // vector<int> a = {34323, 3432};  // 3432 34323
    //                                 // 34323 3432
    // vector<int> a = {432, 43243};  // 43243 432
    //                                // 432 43243

    cout << Solution().largestNumber(a) << endl;
    return 0;
}

// sort(ss.begin(), ss.end(), [](string &a, string &b) {
//             string big, small;
//             if (a.size() > b.size()) {
//                 big   = a;
//                 small = b;
//             } else {
//                 small = a;
//                 big   = b;
//             }

//             if (big.size() > small.size() && big.substr(0, small.size()) == small) {
//                 int i = 0;
//                 while (small.front() == big[small.size() + i] && small.size() + i < big.size())
//                     i++;

//                 cout << i << endl;
//                 if (small.front() > big[small.size() + i])
//                     return a == small ? a < b : b < a;
//                 else
//                     return a == small ? a > b : a < b;
//             } else
//                 return a > b;
//         });