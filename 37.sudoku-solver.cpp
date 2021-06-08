/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 *
 * https://leetcode.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (47.86%)
 * Likes:    2933
 * Dislikes: 110
 * Total Accepted:    244K
 * Total Submissions: 508.4K
 * Testcase Example:
 * '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 *
 * A sudoku solution must satisfy all of the following rules:
 *
 *
 * Each of the digits 1-9 must occur exactly once in each row.
 * Each of the digits 1-9 must occur exactly once in each column.
 * Each of the digits 1-9 must occur exactly once in each of the 9 3x3
 * sub-boxes of the grid.
 *
 *
 * The '.' character indicates empty cells.
 *
 *
 * Example 1:
 *
 *
 * Input: board =
 * [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
 * Output:
 * [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
 * Explanation: The input board is shown above and the only valid solution is
 * shown below:
 *
 *
 *
 *
 *
 * Constraints:
 *
 *
 * board.length == 9
 * board[i].length == 9
 * board[i][j] is a digit or '.'.
 * It is guaranteed that the input board has only one solution.
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    void solveSudoku(vector<vector<char>> &board) { solve(board, 0, 0); }

  private:
    vector<char> const charset = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    bool solve(vector<vector<char>> &board, int startX, int startY) {
        int i = startX, j = startY;
        for (; i < 9; i++) {
            if (j == 9)
                j = 0;
            for (; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (auto &fill : charset) {
                        if (isValid(board, i, j, fill)) {
                            board[i][j] = fill;
                            if (solve(board, j != 8 ? i : i + 1, j != 8 ? j + 1 : 0))
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>> &board, int x, int y, char c) {
        for (int i = 0; i < 9; i++)
            if (board[x][i] == c || board[i][y] == c || board[x / 3 * 3 + i / 3][y / 3 * 3 + i % 3] == c)
                return false;
        return true;
    }
};
// @lc code=end
