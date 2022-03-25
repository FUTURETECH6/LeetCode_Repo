/*
 * @lc app=leetcode id=1765 lang=cpp
 *
 * [1765] Map of Highest Peak
 *
 * https://leetcode.com/problems/map-of-highest-peak/description/
 *
 * algorithms
 * Medium (59.71%)
 * Likes:    472
 * Dislikes: 30
 * Total Accepted:    15.8K
 * Total Submissions: 26.4K
 * Testcase Example:  '[[0,1],[0,0]]'
 *
 * You are given an integer matrix isWater of size m x n that represents a map
 * of land and water cells.
 *
 *
 * If isWater[i][j] == 0, cell (i, j) is a land cell.
 * If isWater[i][j] == 1, cell (i, j) is a water cell.
 *
 *
 * You must assign each cell a height in a way that follows these rules:
 *
 *
 * The height of each cell must be non-negative.
 * If the cell is a water cell, its height must be 0.
 * Any two adjacent cells must have an absolute height difference of at most 1.
 * A cell is adjacent to another cell if the former is directly north, east,
 * south, or west of the latter (i.e., their sides are touching).
 *
 *
 * Find an assignment of heights such that the maximum height in the matrix is
 * maximized.
 *
 * Return an integer matrix height of size m x n where height[i][j] is cell (i,
 * j)'s height. If there are multiple solutions, return any of them.
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input: isWater = [[0,1],[0,0]]
 * Output: [[1,0],[2,1]]
 * Explanation: The image shows the assigned heights of each cell.
 * The blue cell is the water cell, and the green cells are the land cells.
 *
 *
 * Example 2:
 *
 *
 *
 *
 * Input: isWater = [[0,0,1],[1,0,0],[0,0,0]]
 * Output: [[1,1,0],[0,1,1],[1,2,2]]
 * Explanation: A height of 2 is the maximum possible height of any assignment.
 * Any height assignment that has a maximum height of 2 while still meeting the
 * rules will also be accepted.
 *
 *
 *
 * Constraints:
 *
 *
 * m == isWater.length
 * n == isWater[i].length
 * 1 <= m, n <= 1000
 * isWater[i][j] is 0 or 1.
 * There is at least one water cell.
 *
 *
 */

#include "misc.h"
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start

#include <list>
#include <set>
#include <utility>

class Solution {
  private:
    int m, n;

    inline bool isInside(int x, int y) { return x >= 0 && x < m && y >= 0 && y < n; }
    void expand(int x, int y, vector<vector<int>> &map, vector<vector<bool>> &isDone, list<pair<int, int>> &checkQueue) {
        vector<pair<int, int>> ewsn = {{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}};
        for (auto &pos : ewsn) {
            if (isInside(pos.first, pos.second) && !isDone[pos.first][pos.second]) {
                map[pos.first][pos.second]    = map[x][y] + 1;
                isDone[pos.first][pos.second] = true;
                checkQueue.emplace_back(pos.first, pos.second);
            }
        }
    }

  public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater) {
        m           = isWater.size();
        n           = isWater[0].size();
        auto map    = vector<vector<int>>(m, vector<int>(n, 0));
        auto isDone = vector<vector<bool>>(m, vector<bool>(n, false));
        set<pair<int, int>> waters;
        list<pair<int, int>> checkQueue;

        for (auto i = 0; i < m; i++) {
            for (auto j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    waters.emplace(i, j);
                    isDone[i][j] = true;
                    checkQueue.emplace_back(i, j);
                }
            }
        }

        while (!checkQueue.empty()) {
            expand(checkQueue.front().first, checkQueue.front().second, map, isDone, checkQueue);
            checkQueue.pop_front();
        }

        return map;
    }
};

// @lc code=end

int main(int argc, char const *argv[]) {
    vector<vector<int>> a = {{0, 0, 1}, {1, 0, 0}, {0, 0, 0}};
    misc::printVec2D(Solution().highestPeak(a));
    return 0;
}
