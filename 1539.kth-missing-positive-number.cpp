/*
 * @lc app=leetcode id=1539 lang=cpp
 *
 * [1539] Kth Missing Positive Number
 *
 * https://leetcode.com/problems/kth-missing-positive-number/description/
 *
 * algorithms
 * Easy (55.29%)
 * Likes:    2245
 * Dislikes: 166
 * Total Accepted:    153.6K
 * Total Submissions: 277.6K
 * Testcase Example:  '[2,3,4,7,11]\n5'
 *
 * Given an array arr of positive integers sorted in a strictly increasing
 * order, and an integer k.
 *
 * Find the k^th positive integer that is missing from this array.
 *
 *
 * Example 1:
 *
 *
 * Input: arr = [2,3,4,7,11], k = 5
 * Output: 9
 * Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The
 * 5^th missing positive integer is 9.
 *
 *
 * Example 2:
 *
 *
 * Input: arr = [1,2,3,4], k = 2
 * Output: 6
 * Explanation: The missing positive integers are [5,6,7,...]. The 2^nd missing
 * positive integer is 6.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= arr.length <= 1000
 * 1 <= arr[i] <= 1000
 * 1 <= k <= 1000
 * arr[i] < arr[j] for 1 <= i < j <= arr.length
 *
 *
 */

#include "misc.h"
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    int findKthPositive(vector<int> &arr, int k) {
        int res = 0;
        if (k < arr.front())
            return k;
        else if (arr.size() == 1)
            return k + 1;

        k -= arr.front() - 1;
        for (unsigned i = 0; i < arr.size() - 1; i++) {
            if (k <= arr[i + 1] - arr[i] - 1) {
                return arr[i] + k;
            }

            k -= arr[i + 1] - arr[i] - 1;
        }

        return arr.back() + k;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    vector<int> a = {1, 10, 21, 22, 25};
    cout << Solution().findKthPositive(a, 12) << endl;
    return 0;
}
