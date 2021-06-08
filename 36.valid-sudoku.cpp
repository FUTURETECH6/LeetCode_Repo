/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 *
 * https://leetcode.com/problems/valid-sudoku/description/
 *
 * algorithms
 * Medium (51.23%)
 * Likes:    2658
 * Dislikes: 571
 * Total Accepted:    487.6K
 * Total Submissions: 950.5K
 * Testcase Example:
 * '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be
 * validated according to the following rules:
 *
 *
 * Each row must contain the digits 1-9 without repetition.
 * Each column must contain the digits 1-9 without repetition.
 * Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9
 * without repetition.
 *
 *
 * Note:
 *
 *
 * A Sudoku board (partially filled) could be valid but is not necessarily
 * solvable.
 * Only the filled cells need to be validated according to the mentioned
 * rules.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: board =
 * [["5","3",".",".","7",".",".",".","."]
 * ,["6",".",".","1","9","5",".",".","."]
 * ,[".","9","8",".",".",".",".","6","."]
 * ,["8",".",".",".","6",".",".",".","3"]
 * ,["4",".",".","8",".","3",".",".","1"]
 * ,["7",".",".",".","2",".",".",".","6"]
 * ,[".","6",".",".",".",".","2","8","."]
 * ,[".",".",".","4","1","9",".",".","5"]
 * ,[".",".",".",".","8",".",".","7","9"]]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: board =
 * [["8","3",".",".","7",".",".",".","."]
 * ,["6",".",".","1","9","5",".",".","."]
 * ,[".","9","8",".",".",".",".","6","."]
 * ,["8",".",".",".","6",".",".",".","3"]
 * ,["4",".",".","8",".","3",".",".","1"]
 * ,["7",".",".",".","2",".",".",".","6"]
 * ,[".","6",".",".",".",".","2","8","."]
 * ,[".",".",".","4","1","9",".",".","5"]
 * ,[".",".",".",".","8",".",".","7","9"]]
 * Output: false
 * Explanation: Same as Example 1, except with the 5 in the top left corner
 * being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it
 * is invalid.
 *
 *
 *
 * Constraints:
 *
 *
 * board.length == 9
 * board[i].length == 9
 * board[i][j] is a digit or '.'.
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    bool isValidSudoku(vector<vector<char>> &board) {
        for (int x = 0; x < 9; x++) {
            auto mapping = vector<bool>(9, false);
            for (auto &i : board[x])
                if (i >= '1' && i <= '9' && !mapping[i - '1'])
                    mapping[i - '1'] = true;
                else if (i == '.')
                    continue;
                else
                    return false;
        }
        for (int y = 0; y < 9; y++) {
            auto mapping = vector<bool>(9, false);
            for (int x = 0; x < 9; x++)
                if (board[x][y] >= '1' && board[x][y] <= '9' && !mapping[board[x][y] - '1'])
                    mapping[board[x][y] - '1'] = true;
                else if (board[x][y] == '.')
                    continue;
                else
                    return false;
        }
        for (int i = 0; i < 9; i++) {
            auto mapping = vector<bool>(9, false);
            for (int j = 0; j < 9; j++) {
                int x = 3 * (i / 3) + j / 3;
                int y = 3 * (i % 3) + j % 3;
                if (board[x][y] >= '1' && board[x][y] <= '9' && !mapping[board[x][y] - '1'])
                    mapping[board[x][y] - '1'] = true;
                else if (board[x][y] == '.')
                    continue;
                else
                    return false;
            }
        }

        return true;
    }
};
// @lc code=end
#include <iostream>

int main(int argc, char const *argv[]) {
    for (int i = 0; i < 9; i++) {
        auto mapping = vector<bool>(9, false);
        for (int j = 0; j < 9; j++) {
            int x = 3 * (i / 3) + j / 3;
            int y = 3 * (i % 3) + j % 3;
            cout << x << y << endl;
        }
    }
    return 0;
}
