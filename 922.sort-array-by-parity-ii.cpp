/*
 * @lc app=leetcode id=922 lang=cpp
 *
 * [922] Sort Array By Parity II
 *
 * https://leetcode.com/problems/sort-array-by-parity-ii/description/
 *
 * algorithms
 * Easy (70.64%)
 * Likes:    1791
 * Dislikes: 72
 * Total Accepted:    186.5K
 * Total Submissions: 263.9K
 * Testcase Example:  '[4,2,5,7]'
 *
 * Given an array of integers nums, half of the integers in nums are odd, and
 * the other half are even.
 *
 * Sort the array so that whenever nums[i] is odd, i is odd, and whenever
 * nums[i] is even, i is even.
 *
 * Return any answer array that satisfies this condition.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [4,2,5,7]
 * Output: [4,5,2,7]
 * Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been
 * accepted.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [2,3]
 * Output: [2,3]
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= nums.length <= 2 * 10^4
 * nums.length is even.
 * Half of the integers in nums are even.
 * 0 <= nums[i] <= 1000
 *
 *
 *
 * Follow Up: Could you solve it in-place?
 *
 */

#include "misc.h"
#define DEBUG
using namespace std;

// @lc code=start
class Solution {
  private:
    template <typename T>
    void swap(T &a, T &b) {
        T c = a;
        a   = b;
        b   = c;
    }

  public:
    // vector<int> sortArrayByParityII(vector<int> nums) {
    vector<int> sortArrayByParityII(vector<int> &nums) {
        for (unsigned odd_in_even = 0, even_in_odd = 1;;) {
            for (; odd_in_even < nums.size() && nums[odd_in_even] % 2 == 0; odd_in_even += 2)  // is even
                ;
            for (; even_in_odd < nums.size() && nums[even_in_odd] % 2 == 1; even_in_odd += 2)  // is odd
                ;

            if (odd_in_even >= nums.size() || even_in_odd >= nums.size())
                break;

            swap(nums[odd_in_even], nums[even_in_odd]);
        }
        return nums;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    // misc::printVec(Solution().sortArrayByParityII({4, 2, 5, 7}));
    return 0;
}
