/*
 * @lc app=leetcode id=699 lang=cpp
 *
 * [699] Falling Squares
 *
 * https://leetcode.com/problems/falling-squares/description/
 *
 * algorithms
 * Hard (43.69%)
 * Likes:    442
 * Dislikes: 69
 * Total Accepted:    19.2K
 * Total Submissions: 43.9K
 * Testcase Example:  '[[1,2],[2,3],[6,1]]'
 *
 * There are several squares being dropped onto the X-axis of a 2D plane.
 *
 * You are given a 2D integer array positions where positions[i] = [lefti,
 * sideLengthi] represents the i^th square with a side length of sideLengthi
 * that is dropped with its left edge aligned with X-coordinate lefti.
 *
 * Each square is dropped one at a time from a height above any landed squares.
 * It then falls downward (negative Y direction) until it either lands on the
 * top side of another square or on the X-axis. A square brushing the
 * left/right side of another square does not count as landing on it. Once it
 * lands, it freezes in place and cannot be moved.
 *
 * After each square is dropped, you must record the height of the current
 * tallest stack of squares.
 *
 * Return an integer array ans where ans[i] represents the height described
 * above after dropping the i^th square.
 *
 *
 * Example 1:
 *
 *
 * Input: positions = [[1,2],[2,3],[6,1]]
 * Output: [2,5,5]
 * Explanation:
 * After the first drop, the tallest stack is square 1 with a height of 2.
 * After the second drop, the tallest stack is squares 1 and 2 with a height of
 * 5.
 * After the third drop, the tallest stack is still squares 1 and 2 with a
 * height of 5.
 * Thus, we return an answer of [2, 5, 5].
 *
 *
 * Example 2:
 *
 *
 * Input: positions = [[100,100],[200,100]]
 * Output: [100,100]
 * Explanation:
 * After the first drop, the tallest stack is square 1 with a height of 100.
 * After the second drop, the tallest stack is either square 1 or square 2,
 * both with heights of 100.
 * Thus, we return an answer of [100, 100].
 * Note that square 2 only brushes the right side of square 1, which does not
 * count as landing on it.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= positions.length <= 1000
 * 1 <= lefti <= 10^8
 * 1 <= sideLengthi <= 10^6
 *
 *
 */

#include "misc.h"
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start

#include <algorithm>
#include <set>
#include <utility>

class Solution {
  private:
    vector<pair<pair<int, int>, int>> surfaces;  // <<l, r>, height>

    static bool cmpByHeight(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b) { return a.second > b.second; }

    bool tinyThanSur(pair<int, int> surface, int left, int right) { return left >= surface.first && right <= surface.second; }
    bool hugeThanSur(pair<int, int> surface, int left, int right) { return left < surface.first && right > surface.second; }
    bool leftThanSur(pair<int, int> surface, int left, int right) { return !hugeThanSur(surface, left, right) && left < surface.first && right > surface.first; }
    bool rightThanSur(pair<int, int> surface, int left, int right) { return !hugeThanSur(surface, left, right) && left < surface.second && right > surface.second; }

    bool willHold(pair<int, int> surface, int left, int right) {
        return tinyThanSur(surface, left, right) || hugeThanSur(surface, left, right) || leftThanSur(surface, left, right) || rightThanSur(surface, left, right);
    }

  public:
    vector<int> fallingSquares(vector<vector<int>> &positions) {
        vector<int> result;
        // static vector<int> result;
        // result.clear();

        for (auto &input : positions) {
            auto const &lefti = input[0], &heighti = input[1], righti = lefti + input[1];

            if (surfaces.empty()) {
                surfaces.push_back({{lefti, righti}, heighti});
            } else {
                bool flag_touch_ground = true;

                for (auto &surface_with_h : surfaces) {
                    const auto surface   = surface_with_h.first;
                    const auto surface_h = surface_with_h.second;
                    if (!willHold(surface, lefti, righti))
                        continue;

                    if (surface.first == lefti && surface.second == righti) {  // 重合
                        surface_with_h.second += heighti;
                    } else if (lefti == surface.first && righti < surface.second) {  // 左同右小
                        surface_with_h.first.first = righti;
                        surfaces.push_back({{lefti, righti}, surface_h + heighti});
                    } else if (lefti == surface.first && righti > surface.second) {  // 左同右大
                        surface_with_h.first.second = righti;
                        surface_with_h.second += heighti;
                    } else if (lefti > surface.first && righti == surface.second) {  // 右同左小
                        surface_with_h.first.second = lefti;
                        surfaces.push_back({{lefti, righti}, surface_h + heighti});
                    } else if (lefti < surface.first && righti == surface.second) {  // 右同左大
                        surface_with_h.first.first = lefti;
                        surface_with_h.second += heighti;
                    } else if (lefti > surface.first && righti < surface.second) {  //  上比下小（包）
                        surface_with_h.first.second = lefti;
                        surfaces.push_back({{lefti, righti}, surface_h + heighti});
                        surfaces.push_back({{righti, surface.second}, surface_h});
                    } else if (lefti < surface.first && righti > surface.second) {  //  上比下大（压）
                        surface_with_h.first.first  = lefti;
                        surface_with_h.first.second = righti;
                        surface_with_h.second += heighti;
                    } else if (lefti < surface.first && righti > surface.first) {  // 上在下左
                        surface_with_h.first.first = righti;
                        surfaces.push_back({{lefti, righti}, surface_h + heighti});
                    } else if (lefti < surface.second && righti > surface.second) {  // 上在下右
                        surface_with_h.first.second = lefti;
                        surfaces.push_back({{lefti, righti}, surface_h + heighti});
                    }

                    flag_touch_ground = false;
                    break;
                }

                if (flag_touch_ground)
                    surfaces.push_back({{lefti, righti}, heighti});
            }

            sort(surfaces.begin(), surfaces.end(), [](pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b) -> bool { return a.second > b.second; });
            result.push_back(surfaces.front().second);
        }
        return result;
    }
};

// @lc code=end

int main(int argc, char const *argv[]) {
    // vector<vector<int>> a = {{1, 2}, {2, 3}, {6, 1}};
    // vector<vector<int>> a = {{100, 100}, {200, 100}};
    // vector<vector<int>> a = {{1, 5}, {2, 2}, {7, 5}};
    vector<vector<int>> a = {{9, 1}, {6, 5}, {6, 7}};
    misc::printVec(Solution().fallingSquares(a));
    return 0;
}
