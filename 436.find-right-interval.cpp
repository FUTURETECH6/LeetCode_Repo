/*
 * @lc app=leetcode id=436 lang=cpp
 *
 * [436] Find Right Interval
 *
 * https://leetcode.com/problems/find-right-interval/description/
 *
 * algorithms
 * Medium (49.32%)
 * Likes:    1176
 * Dislikes: 249
 * Total Accepted:    76.4K
 * Total Submissions: 154.6K
 * Testcase Example:  '[[1,2]]'
 *
 * You are given an array of intervals, where intervals[i] = [starti, endi] and
 * each starti is unique.
 *
 * The right interval for an interval i is an interval j such that startj >=
 * endi and startj is minimized. Note that i may equal j.
 *
 * Return an array of right interval indices for each interval i. If no right
 * interval exists for interval i, then put -1 at index i.
 *
 *
 * Example 1:
 *
 *
 * Input: intervals = [[1,2]]
 * Output: [-1]
 * Explanation: There is only one interval in the collection, so it outputs
 * -1.
 *
 *
 * Example 2:
 *
 *
 * Input: intervals = [[3,4],[2,3],[1,2]]
 * Output: [-1,0,1]
 * Explanation: There is no right interval for [3,4].
 * The right interval for [2,3] is [3,4] since start0 = 3 is the smallest start
 * that is >= end1 = 3.
 * The right interval for [1,2] is [2,3] since start1 = 2 is the smallest start
 * that is >= end2 = 2.
 *
 *
 * Example 3:
 *
 *
 * Input: intervals = [[1,4],[2,3],[3,4]]
 * Output: [-1,2,-1]
 * Explanation: There is no right interval for [1,4] and [3,4].
 * The right interval for [2,3] is [3,4] since start2 = 3 is the smallest start
 * that is >= end1 = 3.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= intervals.length <= 2 * 10^4
 * intervals[i].length == 2
 * -10^6 <= starti <= endi <= 10^6
 * The start point of each interval is unique.
 *
 *
 */

#include "misc.h"
using namespace std;

// @lc code=start

#include <algorithm>

class Solution {
  public:
    vector<int> findRightInterval(const vector<vector<int>> &intervals) {
        vector<vector<vector<int>>::const_iterator> sorted_intervals;
        for (auto itor = intervals.begin(); itor < intervals.end(); itor++)
            sorted_intervals.push_back(itor);
        sort(sorted_intervals.begin(), sorted_intervals.end(), [](auto &a, auto &b) -> bool { return a->at(0) < b->at(0); });

        vector<int> result;

        for (auto i = intervals.begin(); i < intervals.end(); i++) {
            if (i->at(1) > sorted_intervals.back()->at(0)) {
                result.push_back(-1);
                continue;
            } else if (i->at(0) == i->at(1)) {  // Special case
                result.push_back(i - intervals.begin());
                continue;
            }

            // Binary Search: j1 == j2 - 1 && j1[0] < i[1] && j2[0] >= i[1] ==> j = j2
            size_t j2 = sorted_intervals.size() - 1;
            for (size_t j1 = 0; j2 - j1 > 1;) {
                auto m = (j1 + j2) / 2;
                if (sorted_intervals[m]->at(0) >= i->at(1))  // startj >= endi and startj is minimized
                    j2 = m;
                else
                    j1 = m;
            }
            result.push_back(sorted_intervals[j2] - intervals.begin());
        }

        return result;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    vector<vector<int>> intervals = {{1, 1}, {3, 4}};

    misc::printVec(Solution().findRightInterval(intervals));
    return 0;
}
