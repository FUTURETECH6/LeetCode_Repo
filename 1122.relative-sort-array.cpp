/*
 * @lc app=leetcode id=1122 lang=cpp
 *
 * [1122] Relative Sort Array
 *
 * https://leetcode.com/problems/relative-sort-array/description/
 *
 * algorithms
 * Easy (68.10%)
 * Likes:    1678
 * Dislikes: 101
 * Total Accepted:    126.9K
 * Total Submissions: 186.1K
 * Testcase Example:  '[2,3,1,3,2,4,6,7,9,2,19]\n[2,1,4,3,9,6]'
 *
 * Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all
 * elements in arr2 are also in arr1.
 *
 * Sort the elements of arr1 such that the relative ordering of items in arr1
 * are the same as in arr2. Elements that do not appear in arr2 should be
 * placed at the end of arr1 in ascending order.
 *
 *
 * Example 1:
 *
 *
 * Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
 * Output: [2,2,2,1,4,3,3,9,6,7,19]
 *
 *
 * Example 2:
 *
 *
 * Input: arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
 * Output: [22,28,8,6,17,44]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= arr1.length, arr2.length <= 1000
 * 0 <= arr1[i], arr2[i] <= 1000
 * All the elements of arr2 are distinct.
 * Each arr2[i] is in arr1.
 *
 *
 */

#include "misc.h"
using namespace std;

// @lc code=start

#include <algorithm>
#include <unordered_map>

class Solution {
  public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
        unordered_map<int, int> map;
        for (auto &i : arr1)
            map[i]++;
        arr1.clear();
        for (auto &num : arr2) {
            while (map[num]-- > 0)
                arr1.push_back(num);
            map.erase(num);
        }
        auto sorted_itor = arr1.end();

        for (auto &[num, count] : map)
            while (map[num]-- > 0)
                arr1.push_back(num);

        sort(sorted_itor, arr1.end());

        return arr1;
    }
};
// @lc code=end
