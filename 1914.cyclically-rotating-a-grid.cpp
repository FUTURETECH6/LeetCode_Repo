/*
 * @lc app=leetcode id=1914 lang=cpp
 *
 * [1914] Cyclically Rotating a Grid
 *
 * https://leetcode.com/problems/cyclically-rotating-a-grid/description/
 *
 * algorithms
 * Medium (46.54%)
 * Likes:    171
 * Dislikes: 229
 * Total Accepted:    9.4K
 * Total Submissions: 20K
 * Testcase Example:  '[[40,10],[30,20]]\n1'
 *
 * You are given an m x n integer matrix grid​​​, where m and n are both even
 * integers, and an integer k.
 *
 * The matrix is composed of several layers, which is shown in the below image,
 * where each color is its own layer:
 *
 *
 *
 * A cyclic rotation of the matrix is done by cyclically rotating each layer in
 * the matrix. To cyclically rotate a layer once, each element in the layer
 * will take the place of the adjacent element in the counter-clockwise
 * direction. An example rotation is shown below:
 *
 * Return the matrix after applying k cyclic rotations to it.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[40,10],[30,20]], k = 1
 * Output: [[10,20],[40,30]]
 * Explanation: The figures above represent the grid at every state.
 *
 *
 * Example 2:
 * ⁠
 *
 *
 * Input: grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], k = 2
 * Output: [[3,4,8,12],[2,11,10,16],[1,7,6,15],[5,9,13,14]]
 * Explanation: The figures above represent the grid at every state.
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 2 <= m, n <= 50
 * Both m and n are even integers.
 * 1 <= grid[i][j] <=^ 5000
 * 1 <= k <= 10^9
 *
 */

#include "misc.h"
using namespace std;

// @lc code=start

#include <utility>

class Solution {
  private:
    auto getPath(int m, int n, int level) {
        vector<pair<int, int>> path;

        for (int j = level; j < n - level; j++)
            path.push_back({level, j});
        for (int i = level + 1; i < m - level - 1; i++)
            path.push_back({i, n - level - 1});
        for (int j = n - level - 1; j >= level; j--)
            path.push_back({m - level - 1, j});
        for (int i = m - level - 2; i >= level + 1; i--)
            path.push_back({i, level});

        // for (auto &[x, y] : path)
        //     cout << x << y << endl;
        // cout << endl;

        return path;
    }

  public:
    vector<vector<int>> rotateGrid(vector<vector<int>> &grid, int k) {
        auto m = grid.size(), n = grid.front().size();

        auto newGrid = vector<vector<int>>(m, vector<int>(n));
        for (int level = 0; level < min(m, n) / 2; level++) {
            auto path = getPath(m, n, level);  // clockwise
            for (unsigned i = 0; i < path.size(); i++) {
                auto source                            = (i + k) % path.size();
                newGrid[path[i].first][path[i].second] = grid[path[source].first][path[source].second];
            }
        }

        return newGrid;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    vector<vector<int>> grid = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

    misc::printVec2D(grid);
    misc::printVec2D(Solution().rotateGrid(grid, 2));
    return 0;
}
