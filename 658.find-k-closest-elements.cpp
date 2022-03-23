/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 *
 * https://leetcode.com/problems/find-k-closest-elements/description/
 *
 * algorithms
 * Medium (44.36%)
 * Likes:    4014
 * Dislikes: 409
 * Total Accepted:    270.3K
 * Total Submissions: 609.3K
 * Testcase Example:  '[1,2,3,4,5]\n4\n3'
 *
 * Given a sorted integer array arr, two integers k and x, return the k closest
 * integers to x in the array. The result should also be sorted in ascending
 * order.
 *
 * An integer a is closer to x than an integer b if:
 *
 *
 * |a - x| < |b - x|, or
 * |a - x| == |b - x| and a < b
 *
 *
 *
 * Example 1:
 * Input: arr = [1,2,3,4,5], k = 4, x = 3
 * Output: [1,2,3,4]
 * Example 2:
 * Input: arr = [1,2,3,4,5], k = 4, x = -1
 * Output: [1,2,3,4]
 *
 *
 * Constraints:
 *
 *
 * 1 <= k <= arr.length
 * 1 <= arr.length <= 10^4
 * arr is sorted in ascending order.
 * -10^4 <= arr[i], x <= 10^4
 *
 *
 */

#include "misc.h"
#include <vector>
using namespace std;
// @lc code=start

class Solution {
  private:
    inline int abs(int a) { return a < 0 ? -a : a; }
    inline bool closer(int a, int b, int x) { return abs(a - x) < abs(b - x) || (abs(a - x) == abs(b - x) && a < b); }

  public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        vector<int>::iterator cloest = arr.begin();
        for (auto i = arr.begin(); i != arr.end(); ++i) {
            if (closer(*i, *cloest, x))
                cloest = i;
        }

        vector<int>::iterator l = cloest, r = cloest;
        for (int i = 1; i < k; i++) {
            if (l - 1 >= arr.begin() && r + 1 < arr.end()) {
                if (closer(*(l - 1), *(r + 1), x))
                    l--;
                else
                    r++;
            } else if (l - 1 >= arr.begin()) {
                l--;
            } else if (r + 1 < arr.end()) {
                r++;
            } else {
                // unreachable
            }
        }

        vector<int> res;
        copy(l, r + 1, back_inserter(res));

        return res;
    }
};

// @lc code=end

int main(int argc, char const *argv[]) {
    vector<int> arr = {1, 2, 3, 4, 5};
    auto result     = Solution().findClosestElements(arr, 4, 9);
    misc::printVec(result);
    return 0;
}
