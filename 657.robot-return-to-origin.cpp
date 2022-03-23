/*
 * @lc app=leetcode id=657 lang=cpp
 *
 * [657] Robot Return to Origin
 *
 * https://leetcode.com/problems/robot-return-to-origin/description/
 *
 * algorithms
 * Easy (74.99%)
 * Likes:    1638
 * Dislikes: 713
 * Total Accepted:    324K
 * Total Submissions: 432.1K
 * Testcase Example:  '"UD"'
 *
 * There is a robot starting at the position (0, 0), the origin, on a 2D plane.
 * Given a sequence of its moves, judge if this robot ends up at (0, 0) after
 * it completes its moves.
 *
 * You are given a string moves that represents the move sequence of the robot
 * where moves[i] represents its i^th move. Valid moves are 'R' (right), 'L'
 * (left), 'U' (up), and 'D' (down).
 *
 * Return true if the robot returns to the origin after it finishes all of its
 * moves, or false otherwise.
 *
 * Note: The way that the robot is "facing" is irrelevant. 'R' will always make
 * the robot move to the right once, 'L' will always make it move left, etc.
 * Also, assume that the magnitude of the robot's movement is the same for each
 * move.
 *
 *
 * Example 1:
 *
 *
 * Input: moves = "UD"
 * Output: true
 * Explanation: The robot moves up once, and then down once. All moves have the
 * same magnitude, so it ended up at the origin where it started. Therefore, we
 * return true.
 *
 *
 * Example 2:
 *
 *
 * Input: moves = "LL"
 * Output: false
 * Explanation: The robot moves left twice. It ends up two "moves" to the left
 * of the origin. We return false because it is not at the origin at the end of
 * its moves.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= moves.length <= 2 * 10^4
 * moves only contains the characters 'U', 'D', 'L' and 'R'.
 *
 *
 */

#include "misc.h"
#include <string>
using namespace std;

// @lc code=start
class Solution {
  private:
    int x, y;

  public:
    bool judgeCircle(string moves) {
        for (auto &i : moves) {
            switch (i) {
                case 'U': y++; break;
                case 'D': y--; break;
                case 'L': x--; break;
                case 'R': x++; break;
                default: break;
            }
        }
        return x == 0 && y == 0;
    }
};
// @lc code=end
