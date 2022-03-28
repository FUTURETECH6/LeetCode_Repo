/*
 * @lc app=leetcode id=2170 lang=cpp
 *
 * [2170] Minimum Operations to Make the Array Alternating
 *
 * https://leetcode.com/problems/minimum-operations-to-make-the-array-alternating/description/
 *
 * algorithms
 * Medium (32.66%)
 * Likes:    334
 * Dislikes: 253
 * Total Accepted:    14.9K
 * Total Submissions: 45.4K
 * Testcase Example:  '[3,1,3,2,4,3]'
 *
 * You are given a 0-indexed array nums consisting of n positive integers.
 *
 * The array nums is called alternating if:
 *
 *
 * nums[i - 2] == nums[i], where 2 <= i <= n - 1.
 * nums[i - 1] != nums[i], where 1 <= i <= n - 1.
 *
 *
 * In one operation, you can choose an index i and change nums[i] into any
 * positive integer.
 *
 * Return the minimum number of operations required to make the array
 * alternating.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [3,1,3,2,4,3]
 * Output: 3
 * Explanation:
 * One way to make the array alternating is by converting it to [3,1,3,1,3,1].
 * The number of operations required in this case is 3.
 * It can be proven that it is not possible to make the array alternating in
 * less than 3 operations.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,2,2,2]
 * Output: 2
 * Explanation:
 * One way to make the array alternating is by converting it to [1,2,1,2,1].
 * The number of operations required in this case is 2.
 * Note that the array cannot be converted to [2,2,2,2,2] because in this case
 * nums[0] == nums[1] which violates the conditions of an alternating
 * array.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^5
 *
 *
 */

#include "misc.h"
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start

#include <algorithm>
#include <map>

class Solution {
  private:
    static bool cmp(pair<int, unsigned> &a, pair<int, unsigned> &b) { return a.second > b.second; }

  public:
    int minimumOperations(vector<int> &nums) {
        if (nums.size() < 2)
            return 0;

        map<int, unsigned> odd_map, even_map;

        for (auto i = 0; i < nums.size(); i++) {
            if (i % 2 == 1) {
                if (odd_map.count(nums[i]) == 1)
                    odd_map[nums[i]]++;
                else
                    odd_map[nums[i]] = 1;
            } else {
                if (even_map.count(nums[i]) == 1)
                    even_map[nums[i]]++;
                else
                    even_map[nums[i]] = 1;
            }
        }

        vector<pair<int, unsigned>> odd_vec_pair, even_vec_pair;

        copy(odd_map.begin(), odd_map.end(), back_inserter(odd_vec_pair));
        copy(even_map.begin(), even_map.end(), back_inserter(even_vec_pair));
        sort(odd_vec_pair.begin(), odd_vec_pair.end(), cmp);
        sort(even_vec_pair.begin(), even_vec_pair.end(), cmp);

        if (odd_vec_pair[0].first != even_vec_pair[0].first)
            return nums.size() - odd_vec_pair[0].second - even_vec_pair[0].second;
        else if (odd_vec_pair.size() == 1 && even_vec_pair.size() == 1)
            return nums.size() - max(odd_vec_pair[0].second, even_vec_pair[0].second);
        else if (odd_vec_pair.size() == 1)
            return nums.size() - odd_vec_pair[0].second - even_vec_pair[1].second;
        else if (even_vec_pair.size() == 1)
            return nums.size() - odd_vec_pair[1].second - even_vec_pair[0].second;
        else
            return nums.size() - max(odd_vec_pair[0].second + even_vec_pair[1].second, odd_vec_pair[1].second + even_vec_pair[0].second);
    }
};

// @lc code=end

int main(int argc, char const *argv[]) {
    vector<int> a = {1, 1, 1, 1, 1};
    cout << Solution().minimumOperations(a) << endl;
    return 0;
}
