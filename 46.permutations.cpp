/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (68.90%)
 * Likes:    7246
 * Dislikes: 143
 * Total Accepted:    900.2K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,3]'
 *
 * Given an array nums of distinct integers, return all the possible
 * permutations. You can return the answer in any order.
 *
 *
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * Example 2:
 * Input: nums = [0,1]
 * Output: [[0,1],[1,0]]
 * Example 3:
 * Input: nums = [1]
 * Output: [[1]]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * All the integers of nums are unique.
 *
 *
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution {
  private:
    vector<vector<int>> result;

    void foo(vector<int> &nums, vector<int>::iterator begin) {
        if (begin == nums.end() - 1) {
            result.push_back(nums);
            return;
        }
        // nums[0:begin) unchanged
        for (auto itor = begin; itor < nums.end(); itor++) {
            swap(*begin, *itor);
            foo(nums, begin + 1);
            swap(*begin, *itor);
        }
    }

  public:
    vector<vector<int>> permute(vector<int> &nums) {
        foo(nums, nums.begin());
        return result;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    vector<int> nums = {1, 2, 3};
    Solution().permute(nums);
    return 0;
}

/*
1234
1243
1324
1342
1423
1432
*/