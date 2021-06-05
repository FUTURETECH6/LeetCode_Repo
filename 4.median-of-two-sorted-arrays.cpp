/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (31.70%)
 * Likes:    10109
 * Dislikes: 1538
 * Total Accepted:    944.8K
 * Total Submissions: 3M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return
 * the median of the two sorted arrays.
 *
 * The overall run time complexity should be O(log (m+n)).
 *
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,3], nums2 = [2]
 * Output: 2.00000
 * Explanation: merged array = [1,2,3] and median is 2.
 *
 *
 * Example 2:
 *
 *
 * Input: nums1 = [1,2], nums2 = [3,4]
 * Output: 2.50000
 * Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 *
 *
 * Example 3:
 *
 *
 * Input: nums1 = [0,0], nums2 = [0,0]
 * Output: 0.00000
 *
 *
 * Example 4:
 *
 *
 * Input: nums1 = [], nums2 = [1]
 * Output: 1.00000
 *
 *
 * Example 5:
 *
 *
 * Input: nums1 = [2], nums2 = []
 * Output: 2.00000
 *
 *
 *
 * Constraints:
 *
 *
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -10^6 <= nums1[i], nums2[i] <= 10^6
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        sz1 = nums1.size();
        sz2 = nums2.size();

        if (sz1 == 0)
            return sz2 % 2 ? (double)nums2[sz2 / 2]                               // odd
                           : (double)(nums2[sz2 / 2 - 1] + nums2[sz2 / 2]) / 2.;  // even
        if (sz2 == 0)
            return sz1 % 2 ? (double)nums1[sz1 / 2]                               // odd
                           : (double)(nums1[sz1 / 2 - 1] + nums1[sz1 / 2]) / 2.;  // even
        int const tot_sz = sz1 + sz2;
        return tot_sz % 2 ? Kth(nums1, nums2, tot_sz / 2)
                          : (Kth(nums1, nums2, tot_sz / 2 - 1) + Kth(nums1, nums2, tot_sz / 2)) / 2.;
    }

  private:
    int sz1, sz2;

    int Kth(vector<int> &nums1, vector<int> &nums2, int k) {
        int L1 = 0, L2 = 0, R1 = sz1 - 1, R2 = sz2 - 1, M1 = (L1 + R1) / 2, M2 = (L2 + R2) / 2;

        for (; L1 <= R1 && L2 <= R2; M1 = (L1 + R1) / 2, M2 = (L2 + R2) / 2) {

            if (nums1[M1] <= nums2[M2]) {
                if (k <= M1 + M2)  // Reduce M1 + M2
                    R2 = M2 - 1;
                else  // Increase M1 + M2
                    L1 = M1 + 1;
            } else {
                if (k <= M1 + M2)
                    R1 = M1 - 1;
                else
                    L2 = M2 + 1;
            }
        }
        return L1 > R1 ? nums2[k - L1] : nums1[k - L2];
    }
};
// @lc code=end

/*
这题的重点在于Kth()中的四个条件（哪个的mid val大？k是否超过mid index之和？）要把握好这个意义
*/