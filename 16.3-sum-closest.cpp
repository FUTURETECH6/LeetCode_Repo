/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (46.38%)
 * Likes:    3304
 * Dislikes: 175
 * Total Accepted:    586.8K
 * Total Submissions: 1.3M
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [-1,2,1,-4], target = 1
 * Output: 2
 * Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 =
 * 2).
 *
 *
 *
 * Constraints:
 *
 *
 * 3 <= nums.length <= 10^3
 * -10^3 <= nums[i] <= 10^3
 * -10^4 <= target <= 10^4
 *
 *
 */

#include <cstdio>
#include <vector>
using namespace std;
// @lc code=start
#include <algorithm>
#include <cstdlib>
#include <numeric>

class Solution {
  public:
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());

        int closest = accumulate(nums.begin(), nums.begin() + 3, 0);

        for (int i = 0; i < nums.size(); i++) {
            if (closest == target)
                return closest;

            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                if (dist(nums[i] + nums[j] + nums[k], target) < dist(closest, target))
                    closest = nums[i] + nums[j] + nums[k];

                // if (dist(nums[i] + nums[j + 1] + nums[k], target) <
                //     dist(nums[i] + nums[j] + nums[k - 1], target))
                //     j++;
                // else if (dist(nums[i] + nums[j + 1] + nums[k], target) >
                //          dist(nums[i] + nums[j] + nums[k - 1], target))
                //     k--;
                // else {
                //     j++;
                //     k--;
                // }

                /* 👇这样速度比上面快 */
                if (dist(nums[i] + nums[j + 1] + nums[k], target) <
                    dist(nums[i] + nums[j] + nums[k - 1], target))
                    j++;
                else
                    k--;
            }
        }

        return closest;
    }

  private:
    inline int dist(int a, int b) { return abs(a - b); }
};
// @lc code=end
