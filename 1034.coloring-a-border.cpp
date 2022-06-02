/*
 * @lc app=leetcode id=1034 lang=cpp
 *
 * [1034] Coloring A Border
 *
 * https://leetcode.com/problems/coloring-a-border/description/
 *
 * algorithms
 * Medium (48.25%)
 * Likes:    400
 * Dislikes: 595
 * Total Accepted:    22.2K
 * Total Submissions: 45.9K
 * Testcase Example:  '[[1,1],[1,2]]\n0\n0\n3'
 *
 * You are given an m x n integer matrix grid, and three integers row, col, and
 * color. Each value in the grid represents the color of the grid square at
 * that location.
 *
 * Two squares belong to the same connected component if they have the same
 * color and are next to each other in any of the 4 directions.
 *
 * The border of a connected component is all the squares in the connected
 * component that are either 4-directionally adjacent to a square not in the
 * component, or on the boundary of the grid (the first or last row or
 * column).
 *
 * You should color the border of the connected component that contains the
 * square grid[row][col] with color.
 *
 * Return the final grid.
 *
 *
 * Example 1:
 * Input: grid = [[1,1],[1,2]], row = 0, col = 0, color = 3
 * Output: [[3,3],[3,2]]
 * Example 2:
 * Input: grid = [[1,2,2],[2,3,2]], row = 0, col = 1, color = 3
 * Output: [[1,3,3],[2,3,3]]
 * Example 3:
 * Input: grid = [[1,1,1],[1,1,1],[1,1,1]], row = 1, col = 1, color = 2
 * Output: [[2,2,2],[2,1,2],[2,2,2]]
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 50
 * 1 <= grid[i][j], color <= 1000
 * 0 <= row < m
 * 0 <= col < n
 *
 *
 */

#include "misc.h"
using namespace std;

// @lc code=start

#include <deque>
#include <set>

class Solution {
  private:
    int m, n;
    int oldColor;
    set<pair<int, int>> border;

    inline bool isInside(pair<int, int> pos) {
        auto &x = pos.first, &y = pos.second;
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    inline bool isBoarder(pair<int, int> pos, vector<vector<int>> &grid) {
        auto &x = pos.first, &y = pos.second;
        vector<pair<int, int>> ewsn = {{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}};
        for (auto &iPos : ewsn) {
            if (!isInside(iPos))
                return true;
            else if (grid[iPos.first][iPos.second] != grid[pos.first][pos.second])
                return true;
        }
        return false;
    }

    void expand(pair<int, int> pos, vector<vector<int>> &grid, vector<vector<bool>> &isDone, deque<pair<int, int>> &checkQueue) {
        auto &x = pos.first, &y = pos.second;

        if (isBoarder(pos, grid))
            border.insert({pos});
        isDone[x][y] = true;

        vector<pair<int, int>> ewsn = {{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}};
        for (auto &iPos : ewsn) {
            if (isInside(iPos) && !isDone[iPos.first][iPos.second] && grid[iPos.first][iPos.second] == oldColor) {
                checkQueue.emplace_back(iPos.first, iPos.second);
            }
        }
    }

  public:
    vector<vector<int>> colorBorder(vector<vector<int>> &grid, int row, int col, int color) {
        oldColor = grid[row][col];

        if (oldColor == color)
            return grid;

        m = grid.size();
        n = grid.front().size();

        deque<pair<int, int>> checkQueue = {{row, col}};
        auto isDone                      = vector<vector<bool>>(m, vector<bool>(n, false));

        while (!checkQueue.empty()) {
            expand(checkQueue.front(), grid, isDone, checkQueue);
            checkQueue.pop_front();
        }

        for (auto &iPos : border) {
            grid[iPos.first][iPos.second] = color;
        }

        return grid;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {

    vector<vector<int>> grid = {{1, 1, 1, 2, 2}, {2, 1, 2, 2, 2}, {1, 1, 2, 2, 1}};
    misc::printVec2D(grid);

    misc::printVec2D(Solution().colorBorder(grid, 1, 0, 1));
    return 0;
}
