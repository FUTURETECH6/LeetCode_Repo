/*
 * @lc app=leetcode id=1304 lang=cpp
 *
 * [1304] Find N Unique Integers Sum up to Zero
 *
 * https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/description/
 *
 * algorithms
 * Easy (76.89%)
 * Likes:    1060
 * Dislikes: 458
 * Total Accepted:    136.9K
 * Total Submissions: 177.9K
 * Testcase Example:  '5'
 *
 * Given an integer n, return any array containing n unique integers such that
 * they add up to 0.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 5
 * Output: [-7,-1,1,3,4]
 * Explanation: These arrays also are accepted [-5,-1,1,2,3] ,
 * [-3,-1,2,-2,4].
 *
 *
 * Example 2:
 *
 *
 * Input: n = 3
 * Output: [-1,0,1]
 *
 *
 * Example 3:
 *
 *
 * Input: n = 1
 * Output: [0]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 1000
 *
 *
 */

#include "misc.h"
using namespace std;

// @lc code=start
class Solution {
  public:
    vector<int> sumZero(int n) {
        vector<int> result;
        result.reserve(n);

        if (n % 2)
            result.push_back(0);

        for (int i = 1; i <= n / 2; i++) {
            result.push_back(i);
            result.push_back(-i);
        }

        return result;
    }
};
// @lc code=end
