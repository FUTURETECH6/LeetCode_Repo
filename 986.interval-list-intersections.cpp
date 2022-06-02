/*
 * @lc app=leetcode id=986 lang=cpp
 *
 * [986] Interval List Intersections
 *
 * https://leetcode.com/problems/interval-list-intersections/description/
 *
 * algorithms
 * Medium (70.98%)
 * Likes:    4105
 * Dislikes: 84
 * Total Accepted:    294K
 * Total Submissions: 413.6K
 * Testcase Example:  '[[0,2],[5,10],[13,23],[24,25]]\n[[1,5],[8,12],[15,24],[25,26]]'
 *
 * You are given two lists of closed intervals, firstList and secondList, where
 * firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. Each list
 * of intervals is pairwise disjoint and in sorted order.
 *
 * Return the intersection of these two interval lists.
 *
 * A closed interval [a, b] (with a <= b) denotes the set of real numbers x
 * with a <= x <= b.
 *
 * The intersection of two closed intervals is a set of real numbers that are
 * either empty or represented as a closed interval. For example, the
 * intersection of [1, 3] and [2, 4] is [2, 3].
 *
 *
 * Example 1:
 *
 *
 * Input: firstList = [[0,2],[5,10],[13,23],[24,25]], secondList =
 * [[1,5],[8,12],[15,24],[25,26]]
 * Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
 *
 *
 * Example 2:
 *
 *
 * Input: firstList = [[1,3],[5,9]], secondList = []
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= firstList.length, secondList.length <= 1000
 * firstList.length + secondList.length >= 1
 * 0 <= starti < endi <= 10^9
 * endi < starti+1
 * 0 <= startj < endj <= 10^9
 * endj < startj+1
 *
 *
 */

#include "misc.h"
using namespace std;

// @lc code=start

class Solution {
  public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList) {
        vector<vector<int>> result;

        auto &smallList = firstList.size() < secondList.size() ? firstList : secondList, &largeList = firstList.size() < secondList.size() ? secondList : firstList;

        for (auto &i : largeList) {
            for (auto &j : smallList) {
                if (i[1] < j[0])
                    break;
                if (j[1] < i[0])
                    continue;

                if (j[0] <= i[0] && j[1] >= i[1]) {
                    result.push_back({i[0], i[1]});
                    break;
                } else if (i[0] <= j[0] && i[1] >= j[1])
                    result.push_back({j[0], j[1]});
                else if (j[0] <= i[0] && j[1] >= i[0])
                    result.push_back({i[0], j[1]});
                else if (j[0] <= i[1] && j[1] >= i[1])
                    result.push_back({j[0], i[1]});
            }
        }

        return result;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    vector<vector<int>> firstList  = {{5, 10}};
    vector<vector<int>> secondList = {{5, 6}};

    misc::printVec2D(Solution().intervalIntersection(firstList, secondList));
    return 0;
}
