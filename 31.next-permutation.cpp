/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (34.07%)
 * Likes:    5739
 * Dislikes: 1944
 * Total Accepted:    523.8K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 *
 * If such an arrangement is not possible, it must rearrange it as the lowest
 * possible order (i.e., sorted in ascnums.end()ing order).
 *
 * The replacement must be in place and use only constant extra memory.
 *
 *
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: [1,3,2]
 * Example 2:
 * Input: nums = [3,2,1]
 * Output: [1,2,3]
 * Example 3:
 * Input: nums = [1,1,5]
 * Output: [1,5,1]
 * Example 4:
 * Input: nums = [1]
 * Output: [1]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 100
 *
 *
 */

#include <vector>
using namespace std;

// @lc code=start
#include <algorithm>

class Solution {
  public:
    inline void nextPermutation(vector<int> &nums) {
        if (nums.size() & ~1 == 0)  // 0 or 1 num
            return;
        auto i = nums.end() - 2;  // 从右往左第一个逆序数字

        for (; i >= nums.begin() && *(i) >= *(i + 1); i--)  // `>=` 防止 [5,1,1] 这种
            ;

        if (i < nums.begin()) {  // Last perm
            std::reverse(nums.begin(), nums.end());
            return;
        } else {                   // Not last perm
            auto i2 = nums.end();  // 第一个大于该逆序数字(i)的数字

            for (; i2 != nums.begin() && !(*--i2 > *i);)
                ;

            std::iter_swap(i, i2);
            std::reverse(i + 1, nums.end());
            return;
        }
    }
};
// @lc code=end

/*
https://blog.csdn.net/yingyujianmo/article/details/52046398
从右向左找到第一个逆序的数字，例如“95382”的第一个逆序的数字是‘3’；
从右向左找到第一个大于该逆序数字的数字，“95382”中从右向左大于‘3’
的第一个数字是‘8’；
交换这两个数字的位置，得到“95832”；
再将第一个逆序数字所在位置之后的数字翻转，即得到该排列的下一个排列，
即“95823”.
*/

int main(int argc, char const *argv[]) {
    vector<int> a = {5, 1, 1};
    Solution().nextPermutation(a);
    return 0;
}
