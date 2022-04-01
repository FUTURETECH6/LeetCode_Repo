/*
 * @lc app=leetcode id=861 lang=cpp
 *
 * [861] Score After Flipping Matrix
 *
 * https://leetcode.com/problems/score-after-flipping-matrix/description/
 *
 * algorithms
 * Medium (74.79%)
 * Likes:    1012
 * Dislikes: 161
 * Total Accepted:    34K
 * Total Submissions: 45.4K
 * Testcase Example:  '[[0,0,1,1],[1,0,1,0],[1,1,0,0]]'
 *
 * You are given an m x n binary matrix grid.
 *
 * A move consists of choosing any row or column and toggling each value in
 * that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).
 *
 * Every row of the matrix is interpreted as a binary number, and the score of
 * the matrix is the sum of these numbers.
 *
 * Return the highest possible score after making any number of moves
 * (including zero moves).
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
 * Output: 39
 * Explanation: 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [[0]]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 20
 * grid[i][j] is either 0 or 1.
 *
 *
 */

#include "misc.h"
#include <vector>
using namespace std;

// @lc code=start

#include <algorithm>
#include <numeric>

class Solution {
  private:
    void flip(vector<int> &row) {
        for (auto &i : row)
            i = !i;
    }

  public:
    int matrixScore(vector<vector<int>> &grid) {
        for (auto &row : grid)
            if (row[0] == 0)
                flip(row);

        int base = 1, result = 0;
        for (int i = grid.front().size() - 1; i >= 0; i--) {
            int count = count_if(grid.begin(), grid.end(), [i](vector<int> &row) -> bool { return row[i] == 1; });
            count     = max(count, (int)grid.size() - count);  // max(num of 1, num of 0)
            result += base * count;
            base <<= 1;
        }

        // misc::printVec2D(grid);

        return result;
    }
};

// @lc code=end

int main(int argc, char const *argv[]) {
    vector<vector<int>> a = {{0, 0, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 0}};
    cout << Solution().matrixScore(a) << endl;
    return 0;
}
