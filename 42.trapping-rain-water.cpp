/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (53.19%)
 * Likes:    13549
 * Dislikes: 193
 * Total Accepted:    851K
 * Total Submissions: 1.6M
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it can trap after raining.
 *
 *
 * Example 1:
 *
 *
 * Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * Explanation: The above elevation map (black section) is represented by array
 * [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue
 * section) are being trapped.
 *
 *
 * Example 2:
 *
 *
 * Input: height = [4,2,0,3,2,5]
 * Output: 9
 *
 *
 *
 * Constraints:
 *
 *
 * n == height.length
 * 1 <= n <= 2 * 10^4
 * 0 <= height[i] <= 10^5
 *
 *
 */

#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
#include <algorithm>

class Solution {
  public:
    int trap(vector<int> &heights) {
        auto n               = heights.size();
        auto heightestLoc    = max_element(heights.begin(), heights.end());
        unsigned long volume = 0;

        int waterHeight = 0;
        for (auto loc = heights.begin(); loc < heightestLoc; loc++) {
            if (*loc > waterHeight)
                waterHeight = *loc;
            else
                volume += waterHeight - *loc;
        }
        waterHeight = 0;
        for (auto loc = heights.end() - 1; loc > heightestLoc; loc--) {
            if (*loc > waterHeight)
                waterHeight = *loc;
            else
                volume += waterHeight - *loc;
        }
        return volume;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    vector<int> nums = {4, 2, 0, 3, 2, 5};
    cout << Solution().trap(nums) << endl;
    return 0;
}
