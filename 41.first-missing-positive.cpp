/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 *
 * https://leetcode.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (34.83%)
 * Likes:    6767
 * Dislikes: 1104
 * Total Accepted:    536.6K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,2,0]'
 *
 * Given an unsorted integer array nums, return the smallest missing positive
 * integer.
 *
 * You must implement an algorithm that runs in O(n) time and uses constant
 * extra space.
 *
 *
 * Example 1:
 * Input: nums = [1,2,0]
 * Output: 3
 * Example 2:
 * Input: nums = [3,4,-1,1]
 * Output: 2
 * Example 3:
 * Input: nums = [7,8,9,11,12]
 * Output: 1
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 5 * 10^5
 * -2^31 <= nums[i] <= 2^31 - 1
 *
 *
 */

#include <iostream>
#include <vector>
using namespace std;
// @lc code=start

class Solution {

  public:
    int firstMissingPositive(vector<int> &nums) {
        const int size = nums.size();
        auto mapping   = vector<bool>(size, false);

        for (auto &num : nums) {
            if (1 <= num && num <= size)
                mapping[num - 1] = true;
        }
        for (int i = 1; i <= size; i++)
            if (!mapping[i - 1])
                return i;
        return size + 1;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    vector<int> nums = {1, 2, 3, 4};
    cout << Solution().firstMissingPositive(nums) << endl;
    return 0;
}
