/*
 * @lc app=leetcode id=1200 lang=cpp
 *
 * [1200] Minimum Absolute Difference
 *
 * https://leetcode.com/problems/minimum-absolute-difference/description/
 *
 * algorithms
 * Easy (69.86%)
 * Likes:    1442
 * Dislikes: 58
 * Total Accepted:    117.3K
 * Total Submissions: 167.9K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Given an array of distinct integers arr, find all pairs of elements with the
 * minimum absolute difference of any two elements.
 *
 * Return a list of pairs in ascending order(with respect to pairs), each pair
 * [a, b] follows
 *
 *
 * a, b are from arr
 * a < b
 * b - a equals to the minimum absolute difference of any two elements in
 * arr
 *
 *
 *
 * Example 1:
 *
 *
 * Input: arr = [4,2,1,3]
 * Output: [[1,2],[2,3],[3,4]]
 * Explanation: The minimum absolute difference is 1. List all pairs with
 * difference equal to 1 in ascending order.
 *
 * Example 2:
 *
 *
 * Input: arr = [1,3,6,10,15]
 * Output: [[1,3]]
 *
 *
 * Example 3:
 *
 *
 * Input: arr = [3,8,-10,23,19,-4,-14,27]
 * Output: [[-14,-10],[19,23],[23,27]]
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= arr.length <= 10^5
 * -10^6 <= arr[i] <= 10^6
 *
 *
 */

#include "misc.h"
#include <vector>
using namespace std;

// @lc code=start

#include <algorithm>
#include <numeric>
#include <utility>

struct Diff {
    vector<int> vals;
    unsigned abs_diff;

    Diff(int a, int b) : vals({min(a, b), max(a, b)}), abs_diff(abs(a - b)) {}
    bool operator<(Diff &that) { return this->abs_diff < that.abs_diff; }
};

class Solution {
  public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr) {
        vector<vector<int>> result;
        vector<Diff> diff_arr;
        sort(arr.begin(), arr.end());

        for (unsigned i = 1; i < arr.size(); i++) {
            diff_arr.emplace_back(arr[i], arr[i - 1]);
        }

        auto min_diff = min_element(diff_arr.begin(), diff_arr.end())->abs_diff;
        for (auto &i : diff_arr)
            if (i.abs_diff == min_diff)
                result.push_back(i.vals);
        return result;
    }
};

// @lc code=end

int main(int argc, char const *argv[]) {
    vector<int> a = {3, 8, -10, 23, 19, -4, -14, 27};

    misc::printVec2D(Solution().minimumAbsDifference(a));
    return 0;
}
