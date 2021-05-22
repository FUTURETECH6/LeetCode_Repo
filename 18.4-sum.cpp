/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (35.33%)
 * Likes:    3329
 * Dislikes: 417
 * Total Accepted:    416.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers, return an array of all the unique
 * quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
 *
 *
 * 0 <= a, b, c, d < n
 * a, b, c, and d are distinct.
 * nums[a] + nums[b] + nums[c] + nums[d] == target
 *
 *
 * You may return the answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,0,-1,0,-2,2], target = 0
 * Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [2,2,2,2,2], target = 8
 * Output: [[2,2,2,2]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 200
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 *
 *
 */

#include <vector>
using namespace std;
// @lc code=start
#include <algorithm>
#include <stdexcept>

class Solution {
  public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        return kSum(nums, target, nums.begin(), 4);
    }

  private:
    vector<vector<int>> kSum(
        vector<int> &nums, int target, vector<int>::iterator start_itor, int k) {
        vector<vector<int>> res;

        if (start_itor == nums.end()      // has gone to the tail
            || *start_itor * k > target   // must exceed
            || target > nums.back() * k)  // must inadequate
            return res;
        if (k == 1) {
            for (auto i = nums.begin(); i < nums.end(); i++)
                if (*i == target                // match
                    && (i == nums.begin()       // is first
                           || *i != *(i - 1)))  // pass same vals
                    res.push_back({*i});
        } else if (k > 1) {  // k > 1
            for (auto i = start_itor; i < nums.end(); i++)
                if (i == start_itor     // is first
                    || *i != *(i - 1))  // pass same vals
                    for (auto &set : kSum(nums, target - *i, i + 1, k - 1)) {
                        res.push_back({*i});
                        res.back().insert(res.back().end(), set.begin(), set.end());
                    }
        } else {  // int k <= 0
            throw out_of_range("Invalid k out of range.");
        }

        return res;
    }
};
// @lc code=end

/*
网上的submission用了 2sum 和 >2sum，我直接用了 1sum 和 >1sum
*/

// case 2:
//     for (int i = start, j = nums.size() - 1; i < j;) {
//         const int sum = nums[i] + nums[j];
//         if (sum < target                             // need bigger
//             || i > start && nums[i] == nums[i - 1])  // pass same vals
//             i++;
//         else if (sum > target  // need smaller
//                  ||
//                  j < nums.size() - 1 && nums[j] == nums[j + 1])  // pass same
//                  vals
//             j--;
//         else  // sum == target, find
//             res.push_back({nums[i++], nums[j--]});
//     }
//     break;
