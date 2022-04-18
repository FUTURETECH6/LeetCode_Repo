/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 *
 * https://leetcode.com/problems/range-sum-query-2d-immutable/description/
 *
 * algorithms
 * Medium (47.19%)
 * Likes:    2504
 * Dislikes: 243
 * Total Accepted:    221.1K
 * Total Submissions: 465K
 * Testcase Example:  '["NumMatrix","sumRegion","sumRegion","sumRegion"]\n' +
  '[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]'
 *
 * Given a 2D matrix matrix, handle multiple queries of the following
 * type:
 *
 *
 * Calculate the sum of the elements of matrix inside the rectangle defined by
 * its upper left corner (row1, col1) and lower right corner (row2, col2).
 *
 *
 * Implement the NumMatrix class:
 *
 *
 * NumMatrix(int[][] matrix) Initializes the object with the integer matrix
 * matrix.
 * int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the
 * elements of matrix inside the rectangle defined by its upper left corner
 * (row1, col1) and lower right corner (row2, col2).
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["NumMatrix", "sumRegion", "sumRegion", "sumRegion"]
 * [[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1,
 * 0, 3, 0, 5]]], [2, 1, 4, 3], [1, 1, 2, 2], [1, 2, 2, 4]]
 * Output
 * [null, 8, 11, 12]
 *
 * Explanation
 * NumMatrix numMatrix = new NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1,
 * 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]);
 * numMatrix.sumRegion(2, 1, 4, 3); // return 8 (i.e sum of the red rectangle)
 * numMatrix.sumRegion(1, 1, 2, 2); // return 11 (i.e sum of the green
 * rectangle)
 * numMatrix.sumRegion(1, 2, 2, 4); // return 12 (i.e sum of the blue
 * rectangle)
 *
 *
 *
 * Constraints:
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 200
 * -10^5 <= matrix[i][j] <= 10^5
 * 0 <= row1 <= row2 < m
 * 0 <= col1 <= col2 < n
 * At most 10^4 calls will be made to sumRegion.
 *
 *
 */

#include "misc.h"
using namespace std;

// @lc code=start
class NumMatrix {
  private:
    vector<vector<int>> sumMatrix;

  public:
    NumMatrix(vector<vector<int>> &matrix) {
        sumMatrix.resize(matrix.size(), vector<int>(matrix.front().size(), 0));

        sumMatrix[0][0] = matrix[0][0];

        for (unsigned j = 1; j < matrix.front().size(); j++) {
            sumMatrix[0][j] = matrix[0][j] + sumMatrix[0][j - 1];
        }

        for (unsigned i = 1; i < matrix.size(); i++) {
            sumMatrix[i][0] = matrix[i][0] + sumMatrix[i - 1][0];
            for (unsigned j = 1; j < matrix.front().size(); j++) {
                sumMatrix[i][j] = sumMatrix[i][j - 1] + sumMatrix[i - 1][j] - sumMatrix[i - 1][j - 1] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sumMatrix[row2][col2] - (col1 == 0 ? 0 : sumMatrix[row2][col1 - 1]) - (row1 == 0 ? 0 : sumMatrix[row1 - 1][col2]) + (row1 == 0 || col1 == 0 ? 0 : sumMatrix[row1 - 1][col1 - 1]);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

int main(int argc, char const *argv[]) {
    vector<vector<int>> matrix = {{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};

    auto p = new NumMatrix(matrix);
    return 0;
}
