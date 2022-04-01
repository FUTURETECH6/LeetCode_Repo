/*
 * @lc app=leetcode id=850 lang=cpp
 *
 * [850] Rectangle Area II
 *
 * https://leetcode.com/problems/rectangle-area-ii/description/
 *
 * algorithms
 * Hard (53.27%)
 * Likes:    770
 * Dislikes: 51
 * Total Accepted:    29K
 * Total Submissions: 54.5K
 * Testcase Example:  '[[0,0,2,2],[1,0,2,3],[1,0,3,1]]'
 *
 * You are given a 2D array of axis-aligned rectangles. Each rectangle[i] =
 * [xi1, yi1, xi2, yi2] denotes the i^th rectangle where (xi1, yi1) are the
 * coordinates of the bottom-left corner, and (xi2, yi2) are the coordinates of
 * the top-right corner.
 *
 * Calculate the total area covered by all rectangles in the plane. Any area
 * covered by two or more rectangles should only be counted once.
 *
 * Return the total area. Since the answer may be too large, return it modulo
 * 10^9 + 7.
 *
 *
 * Example 1:
 *
 *
 * Input: rectangles = [[0,0,2,2],[1,0,2,3],[1,0,3,1]]
 * Output: 6
 * Explanation: A total area of 6 is covered by all three rectangales, as
 * illustrated in the picture.
 * From (1,1) to (2,2), the green and red rectangles overlap.
 * From (1,0) to (2,3), all three rectangles overlap.
 *
 *
 * Example 2:
 *
 *
 * Input: rectangles = [[0,0,1000000000,1000000000]]
 * Output: 49
 * Explanation: The answer is 10^18 modulo (10^9 + 7), which is 49.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= rectangles.length <= 200
 * rectanges[i].length == 4
 * 0 <= xi1, yi1, xi2, yi2 <= 10^9
 *
 *
 */

#include "misc.h"
#include <vector>
using namespace std;

// @lc code=start

#include <algorithm>
#include <numeric>
#include <set>

// x1(vec[0]), y1(vec[1]), x2(vec[2]), y2(vec[3])
class Solution {
  private:
    const int modulo = 1e9 + 7;

    int lineLenAt(int const y, vector<vector<int>> const &rectangles) {
        vector<pair<int, int>> lines;

        for (auto &rec : rectangles) {  // rectangles has been sort by x1
            if (!(y >= rec[1] && y < rec[3]))
                continue;
            if (lines.empty())
                lines.push_back({rec[0], rec[2]});
            else {
                if (lines.back().second < rec[0])  // no overlap
                    lines.push_back({rec[0], rec[2]});
                else if (rec[2] > lines.back().second)  // overlap but not inside
                    lines.back().second = rec[2];
            }
        }

        return accumulate(lines.begin(), lines.end(), 0, [](int &val, pair<int, int> &line) { return val + line.second - line.first; });
    }

  public:
    int rectangleArea(vector<vector<int>> &rectangles) {
        long result = 0;

        sort(rectangles.begin(), rectangles.end(), [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });  // sort by x1

        set<int> all_y_set;
        for (auto &rec : rectangles) {
            all_y_set.insert(rec[1]);
            all_y_set.insert(rec[3]);
        }
        auto all_y_vec = vector<int>(all_y_set.begin(), all_y_set.end());
        sort(all_y_vec.begin(), all_y_vec.end());

        for (int i = 0; i < all_y_vec.size() - 1; i++) {
            result += long(lineLenAt(all_y_vec[i], rectangles)) * long(all_y_vec[i + 1] - all_y_vec[i]) % modulo;
            result %= modulo;
        }

        return result;
    }
};

// @lc code=end

int main(int argc, char const *argv[]) {
    // vector<vector<int>> a = {{0, 0, 2, 2}, {1, 0, 2, 3}, {1, 0, 3, 1}};  // 6
    vector<vector<int>> a = {{49, 40, 62, 100}, {11, 83, 31, 99}, {19, 39, 30, 99}};  // 1584
    cout << Solution().rectangleArea(a) << endl;

    return 0;
}
