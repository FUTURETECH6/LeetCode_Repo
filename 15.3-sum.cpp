/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (28.49%)
 * Likes:    10622
 * Dislikes: 1078
 * Total Accepted:    1.3M
 * Total Submissions: 4.6M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an integer array nums, return all the triplets [nums[i], nums[j],
 * nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] +
 * nums[k] == 0.
 *
 * Notice that the solution set must not contain duplicate triplets.
 *
 *
 * Example 1:
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Example 2:
 * Input: nums = []
 * Output: []
 * Example 3:
 * Input: nums = [0]
 * Output: []
 *
 *
 * Constraints:
 *
 *
 * 0 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 *
 *
 */

#include <cstdio>
#include <vector>
using namespace std;
// @lc code=start
#include <algorithm>

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1, k = nums.size() - 1;

            while (j < k) {
                if (nums[j] + nums[k] < -nums[i])
                    j++;
                else if (nums[j] + nums[k] > -nums[i])
                    k--;
                else {  // 3sum == 0
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    res.push_back(triplet);
                    while (j < k && nums[j] == triplet[1])
                        j++;
                    while (j < k && nums[k] == triplet[2])
                        k--;
                }
            }
            while (i + 1 < nums.size() && nums[i] == nums[i + 1])
                i++;
        }

        return res;
    }
};
// @lc code=end
/*
本来的查重是这样的：

```cpp
bool exists = false;
for (auto &vec : res)
    if (vec[0] == nums[i] && vec[1] == nums[j] && vec[2] == nums[k]) {
        exists = true;
        break;
    }
if (!exists) {
    vector<int> tuple = {nums[i], nums[j], nums[k]};
    res.push_back(tuple);
}
j++;
k--;
```

后来参考solution改成现在这样。

虽然都是O(n^2)但是速度还是差了不少。。。（88/1500）
*/