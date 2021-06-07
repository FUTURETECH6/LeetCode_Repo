/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (37.99%)
 * Likes:    5884
 * Dislikes: 210
 * Total Accepted:    734.2K
 * Total Submissions: 1.9M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 *
 * If target is not found in the array, return [-1, -1].
 *
 * You must write an algorithm with O(log n) runtime complexity.
 *
 *
 * Example 1:
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * Example 2:
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * Example 3:
 * Input: nums = [], target = 0
 * Output: [-1,-1]
 *
 *
 * Constraints:
 *
 *
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums is a non-decreasing array.
 * -10^9 <= target <= 10^9
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    vector<int> searchRange(vector<int> const &nums, int target) {
        if (nums.empty())
            return {-1, -1};
        auto a = findFirst(nums, 0, nums.size() - 1, target);
        auto b = findFirst(nums, 0, nums.size() - 1, target + 1) - 1;
        // 注意这个条件不能用 a>b：对于[1], 1，a=0, b=-1，但是结果不应该是{-1,-1}而是{0,0}
        if (a < nums.size() && nums[a] == target)
            return {a, b >= a ? b : a};
        else
            return {-1, -1};
    }

  private:
    int findFirst(vector<int> const &nums, int L, int R, int target) const {
        if (L > R)
            return L;  // Important
        /* if (L == R) // 这个不能加，不然[2,2],2这个case中，b会为0
               return L; */
        auto mid = (L + R) / 2;
        if (target <= nums[mid])
            return findFirst(nums, L, mid - 1, target);
        else
            return findFirst(nums, mid + 1, R, target);
    }
};
// @lc code=end
int main(int argc, char const *argv[]) {
    vector<int> nums = {2, 2};
    Solution().searchRange(nums, 2);
    return 0;
}
