/*
 * @lc app=leetcode id=1337 lang=cpp
 *
 * [1337] The K Weakest Rows in a Matrix
 *
 * https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/description/
 *
 * algorithms
 * Easy (72.21%)
 * Likes:    2342
 * Dislikes: 129
 * Total Accepted:    158.1K
 * Total Submissions: 212.6K
 * Testcase Example:  '[[1,1,0,0,0],[1,1,1,1,0],[1,0,0,0,0],[1,1,0,0,0],[1,1,1,1,1]]\n3'
 *
 * You are given an m x n binary matrix mat of 1's (representing soldiers) and
 * 0's (representing civilians). The soldiers are positioned in front of the
 * civilians. That is, all the 1's will appear to the left of all the 0's in
 * each row.
 *
 * A row i is weaker than a row j if one of the following is true:
 *
 *
 * The number of soldiers in row i is less than the number of soldiers in row
 * j.
 * Both rows have the same number of soldiers and i < j.
 *
 *
 * Return the indices of the k weakest rows in the matrix ordered from weakest
 * to strongest.
 *
 *
 * Example 1:
 *
 *
 * Input: mat =
 * [[1,1,0,0,0],
 * ⁠[1,1,1,1,0],
 * ⁠[1,0,0,0,0],
 * ⁠[1,1,0,0,0],
 * ⁠[1,1,1,1,1]],
 * k = 3
 * Output: [2,0,3]
 * Explanation:
 * The number of soldiers in each row is:
 * - Row 0: 2
 * - Row 1: 4
 * - Row 2: 1
 * - Row 3: 2
 * - Row 4: 5
 * The rows ordered from weakest to strongest are [2,0,3,1,4].
 *
 *
 * Example 2:
 *
 *
 * Input: mat =
 * [[1,0,0,0],
 * ⁠[1,1,1,1],
 * ⁠[1,0,0,0],
 * ⁠[1,0,0,0]],
 * k = 2
 * Output: [0,2]
 * Explanation:
 * The number of soldiers in each row is:
 * - Row 0: 1
 * - Row 1: 4
 * - Row 2: 1
 * - Row 3: 1
 * The rows ordered from weakest to strongest are [0,2,3,1].
 *
 *
 *
 * Constraints:
 *
 *
 * m == mat.length
 * n == mat[i].length
 * 2 <= n, m <= 100
 * 1 <= k <= m
 * matrix[i][j] is either 0 or 1.
 *
 *
 */

#include "misc.h"
using namespace std;

// @lc code=start

#include <algorithm>

class Solution {
  public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
        vector<unsigned> soldierNum;
        vector<int> result;

        for (unsigned i = 0; i < mat.size(); i++) {
            soldierNum.push_back(find(mat[i].begin(), mat[i].end(), 0) - mat[i].begin());
            result.push_back(i);
        }

        stable_sort(result.begin(), result.end(), [&soldierNum](auto i, auto j) { return soldierNum[i] < soldierNum[j]; });

        result.resize(k);

        return result;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    vector<vector<int>> mat = {{1, 1, 0, 0, 0}, {1, 1, 1, 1, 0}, {1, 0, 0, 0, 0}, {1, 1, 0, 0, 0}, {1, 1, 1, 1, 1}};

    misc::printVec(Solution().kWeakestRows(mat, 3));

    return 0;
}
