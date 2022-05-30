/*
 * @lc app=leetcode id=773 lang=cpp
 *
 * [773] Sliding Puzzle
 *
 * https://leetcode.com/problems/sliding-puzzle/description/
 *
 * algorithms
 * Hard (63.03%)
 * Likes:    1508
 * Dislikes: 39
 * Total Accepted:    72.3K
 * Total Submissions: 114.3K
 * Testcase Example:  '[[1,2,3],[4,0,5]]'
 *
 * On an 2 x 3 board, there are five tiles labeled from 1 to 5, and an empty
 * square represented by 0. A move consists of choosing 0 and a 4-directionally
 * adjacent number and swapping it.
 *
 * The state of the board is solved if and only if the board is
 * [[1,2,3],[4,5,0]].
 *
 * Given the puzzle board board, return the least number of moves required so
 * that the state of the board is solved. If it is impossible for the state of
 * the board to be solved, return -1.
 *
 *
 * Example 1:
 *
 *
 * Input: board = [[1,2,3],[4,0,5]]
 * Output: 1
 * Explanation: Swap the 0 and the 5 in one move.
 *
 *
 * Example 2:
 *
 *
 * Input: board = [[1,2,3],[5,4,0]]
 * Output: -1
 * Explanation: No number of moves will make the board solved.
 *
 *
 * Example 3:
 *
 *
 * Input: board = [[4,1,2],[5,0,3]]
 * Output: 5
 * Explanation: 5 is the smallest number of moves that solves the board.
 * An example path:
 * After move 0: [[4,1,2],[5,0,3]]
 * After move 1: [[4,1,2],[0,5,3]]
 * After move 2: [[0,1,2],[4,5,3]]
 * After move 3: [[1,0,2],[4,5,3]]
 * After move 4: [[1,2,0],[4,5,3]]
 * After move 5: [[1,2,3],[4,5,0]]
 *
 *
 *
 * Constraints:
 *
 *
 * board.length == 2
 * board[i].length == 3
 * 0 <= board[i][j] <= 5
 * Each value board[i][j] is unique.
 *
 *
 */

#define DEBUG
#include "misc.h"
using namespace std;
// @lc code=start

#ifdef DEBUG
#include <cassert>
#endif
#include <queue>
#include <unordered_map>

class Solution {
  private:
    vector<vector<int>> swapBoard(vector<vector<int>> board, int x1, int y1, int x2, int y2) {
#ifdef DEBUG
        assert(x1 >= 0 && x1 < 2);
        assert(x2 >= 0 && x2 < 2);
        assert(y1 >= 0 && y1 < 3);
        assert(y2 >= 0 && y2 < 3);
#endif
        auto tmp      = board[x1][y1];
        board[x1][y1] = board[x2][y2];
        board[x2][y2] = tmp;

        return board;
    }

    int encode(vector<vector<int>> board) { return board[0][0] * (int)1e+5 + board[0][1] * (int)1e+4 + board[0][2] * (int)1e+3 + board[1][0] * (int)1e+2 + board[1][1] * (int)1e+1 + board[1][2]; }
    vector<vector<int>> decode(int x) { return {{x / (int)1e+5, x / (int)1e+4 % 10, x / (int)1e3 % 10}, {x / (int)1e+2 % 10, x / (int)1e+1 % 10, x % 10}}; }

    void calMap(unordered_map<int, int> &map, int target) {
        queue<pair<int, int>> queue;  // {encode_board, step}

        queue.push({123450, 0});

        while (!queue.empty()) {
            auto board               = decode(queue.front().first);
            auto step                = queue.front().second;
            map[queue.front().first] = step;
            if (target == queue.front().first)
                return;
            queue.pop();

            if (board[0][0] == 0) {
                if (map.count(encode(swapBoard(board, 0, 0, 0, 1))) == 0)
                    queue.push({encode(swapBoard(board, 0, 0, 0, 1)), step + 1});
                if (map.count(encode(swapBoard(board, 0, 0, 1, 0))) == 0)
                    queue.push({encode(swapBoard(board, 0, 0, 1, 0)), step + 1});
            } else if (board[0][1] == 0) {
                if (map.count(encode(swapBoard(board, 0, 1, 0, 0))) == 0)
                    queue.push({encode(swapBoard(board, 0, 1, 0, 0)), step + 1});
                if (map.count(encode(swapBoard(board, 0, 1, 0, 2))) == 0)
                    queue.push({encode(swapBoard(board, 0, 1, 0, 2)), step + 1});
                if (map.count(encode(swapBoard(board, 0, 1, 1, 1))) == 0)
                    queue.push({encode(swapBoard(board, 0, 1, 1, 1)), step + 1});
            } else if (board[0][2] == 0) {
                if (map.count(encode(swapBoard(board, 0, 2, 0, 1))) == 0)
                    queue.push({encode(swapBoard(board, 0, 2, 0, 1)), step + 1});
                if (map.count(encode(swapBoard(board, 0, 2, 1, 2))) == 0)
                    queue.push({encode(swapBoard(board, 0, 2, 1, 2)), step + 1});
            } else if (board[1][0] == 0) {
                if (map.count(encode(swapBoard(board, 1, 0, 0, 0))) == 0)
                    queue.push({encode(swapBoard(board, 1, 0, 0, 0)), step + 1});
                if (map.count(encode(swapBoard(board, 1, 0, 1, 1))) == 0)
                    queue.push({encode(swapBoard(board, 1, 0, 1, 1)), step + 1});
            } else if (board[1][1] == 0) {
                if (map.count(encode(swapBoard(board, 1, 1, 1, 0))) == 0)
                    queue.push({encode(swapBoard(board, 1, 1, 1, 0)), step + 1});
                if (map.count(encode(swapBoard(board, 1, 1, 1, 2))) == 0)
                    queue.push({encode(swapBoard(board, 1, 1, 1, 2)), step + 1});
                if (map.count(encode(swapBoard(board, 1, 1, 0, 1))) == 0)
                    queue.push({encode(swapBoard(board, 1, 1, 0, 1)), step + 1});
            } else if (board[1][2] == 0) {
                if (map.count(encode(swapBoard(board, 1, 2, 0, 2))) == 0)
                    queue.push({encode(swapBoard(board, 1, 2, 0, 2)), step + 1});
                if (map.count(encode(swapBoard(board, 1, 2, 1, 1))) == 0)
                    queue.push({encode(swapBoard(board, 1, 2, 1, 1)), step + 1});
            }
        }
    }

  public:
    int slidingPuzzle(vector<vector<int>> &board) {
        unordered_map<int, int> map;
        calMap(map, encode(board));

        if (map.count(encode(board)))
            return map[encode(board)];
        else
            return -1;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    // vector<vector<int>> board = {{4, 1, 2}, {5, 0, 3}};
    // vector<vector<int>> board = {{1, 2, 3}, {4, 0, 5}};
    vector<vector<int>> board = {{1, 2, 3}, {5, 4, 0}};
    cout << Solution().slidingPuzzle(board) << endl;
    return 0;
}
