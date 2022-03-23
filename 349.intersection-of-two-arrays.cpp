/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 *
 * https://leetcode.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (68.69%)
 * Likes:    2626
 * Dislikes: 1865
 * Total Accepted:    634.6K
 * Total Submissions: 923.6K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two integer arrays nums1 and nums2, return an array of their
 * intersection. Each element in the result must be unique and you may return
 * the result in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2]
 *
 *
 * Example 2:
 *
 *
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [9,4]
 * Explanation: [4,9] is also accepted.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums1.length, nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 1000
 *
 *
 */

#include "misc.h"
#include <vector>
using namespace std;

// @lc code=start

#include <set>

class Solution {
  public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        set<int> set1(nums1.begin(), nums1.end()), set2(nums2.begin(), nums2.end());
        set<int> *small, *big;
        vector<int> res;
        if (set1.size() > set2.size()) {
            big   = &set1;
            small = &set2;
        } else {
            big   = &set2;
            small = &set1;
        }

        for (auto &i : *small) {
            if (big->count(i)) {
                res.push_back(i);
            }
        }
        return res;
    }
};

// @lc code=end

int main(int argc, char const *argv[]) {
    vector<int> nums1 = {1, 2, 2, 1}, nums2 = {2, 2};
    auto result = Solution().intersection(nums1, nums2);
    misc::printVec(result);
    return 0;
}
