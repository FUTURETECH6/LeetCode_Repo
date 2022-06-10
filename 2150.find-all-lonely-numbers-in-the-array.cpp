/*
 * @lc app=leetcode id=2150 lang=cpp
 *
 * [2150] Find All Lonely Numbers in the Array
 *
 * https://leetcode.com/problems/find-all-lonely-numbers-in-the-array/description/
 *
 * algorithms
 * Medium (60.48%)
 * Likes:    251
 * Dislikes: 35
 * Total Accepted:    24.5K
 * Total Submissions: 40.5K
 * Testcase Example:  '[10,6,5,8]'
 *
 * You are given an integer array nums. A number x is lonely when it appears
 * only once, and no adjacent numbers (i.e. x + 1 and x - 1) appear in the
 * array.
 *
 * Return all lonely numbers in nums. You may return the answer in any
 * order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [10,6,5,8]
 * Output: [10,8]
 * Explanation:
 * - 10 is a lonely number since it appears exactly once and 9 and 11 does not
 * appear in nums.
 * - 8 is a lonely number since it appears exactly once and 7 and 9 does not
 * appear in nums.
 * - 5 is not a lonely number since 6 appears in nums and vice versa.
 * Hence, the lonely numbers in nums are [10, 8].
 * Note that [8, 10] may also be returned.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,3,5,3]
 * Output: [1,5]
 * Explanation:
 * - 1 is a lonely number since it appears exactly once and 0 and 2 does not
 * appear in nums.
 * - 5 is a lonely number since it appears exactly once and 4 and 6 does not
 * appear in nums.
 * - 3 is not a lonely number since it appears twice.
 * Hence, the lonely numbers in nums are [1, 5].
 * Note that [5, 1] may also be returned.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i] <= 10^6
 *
 *
 */

#include "misc.h"
using namespace std;

// @lc code=start

#include <unordered_map>

class Solution {
  public:
    vector<int> findLonely(vector<int> &nums) {
        unordered_map<int, unsigned> map;
        for (auto i : nums)
            map[i]++;

        nums.clear();

        for (auto &[num, count] : map)
            if (count == 1 && map.count(num - 1) == 0 && map.count(num + 1) == 0)
                nums.push_back(num);

        return nums;
    }
};

// @lc code=end
