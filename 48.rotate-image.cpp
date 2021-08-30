/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 *
 * https://leetcode.com/problems/rotate-image/description/
 *
 * algorithms
 * Medium (63.02%)
 * Likes:    6132
 * Dislikes: 381
 * Total Accepted:    662.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * You are given an n x n 2D matrix representing an image, rotate the image by
 * 90 degrees (clockwise).
 *
 * You have to rotate the image in-place, which means you have to modify the
 * input 2D matrix directly. DO NOT allocate another 2D matrix and do the
 * rotation.
 *
 *
 * Example 1:
 *
 *
 * Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [[7,4,1],[8,5,2],[9,6,3]]
 *
 *
 * Example 2:
 *
 *
 * Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
 * Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 *
 *
 * Example 3:
 *
 *
 * Input: matrix = [[1]]
 * Output: [[1]]
 *
 *
 * Example 4:
 *
 *
 * Input: matrix = [[1,2],[3,4]]
 * Output: [[3,1],[4,2]]
 *
 *
 *
 * Constraints:
 *
 *
 * matrix.length == n
 * matrix[i].length == n
 * 1 <= n <= 20
 * -1000 <= matrix[i][j] <= 1000
 *
 *
 */

#include "misc.h"
#include <vector>
using namespace std;
// @lc code=start
#include <tuple>

class Solution {
  private:
    int n;

    /*
    tmp=next;
    next=this;

    toBeVal=1
    1 2
    4 3
    toBeVal=2
    1 1
    4 3
    toBeVal=3
    1 1
    4 2
    toBeVal=4
    1 1
    3 2

    4 1
    3 2
    */
    void swap4(vector<vector<int>> &matrix, int i, int j) {
        for (int cnt = 0, toBeVal = matrix[i][j]; cnt < 4; cnt++) {
            pair nextPos = make_pair(j, n - 1 - i);  // must make it read-only
            i            = nextPos.first;
            j            = nextPos.second;
            int tmp      = matrix[i][j];
            matrix[i][j] = toBeVal;
            toBeVal      = tmp;
        }
    }

  public:
    //[i][j] -> [j][n-1-i]
    void rotate(vector<vector<int>> &matrix) {
        n = matrix.size();
        if (n % 2) {
            for (int i = 0; i < n / 2 + 1; i++) {
                for (int j = 0; j < n / 2; j++) {
                    swap4(matrix, i, j);
                }
            }
        } else
            for (int i = 0; i < n / 2; i++) {
                for (int j = 0; j < n / 2; j++) {
                    swap4(matrix, i, j);
                }
            }
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    vector<vector<int>> matrix = {{1, 2}, {4, 3}};
    Solution().rotate(matrix);
    misc::printVec2D(matrix);
    return 0;
}
