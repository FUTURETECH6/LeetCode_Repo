/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 *
 * https://leetcode.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (63.77%)
 * Likes:    2687
 * Dislikes: 73
 * Total Accepted:    281.4K
 * Total Submissions: 441.2K
 * Testcase Example:  '3\n7'
 *
 * Find all valid combinations of k numbers that sum up to n such that the
 * following conditions are true:
 *
 *
 * Only numbers 1 through 9 are used.
 * Each number is used at most once.
 *
 *
 * Return a list of all possible valid combinations. The list must not contain
 * the same combination twice, and the combinations may be returned in any
 * order.
 *
 *
 * Example 1:
 *
 *
 * Input: k = 3, n = 7
 * Output: [[1,2,4]]
 * Explanation:
 * 1 + 2 + 4 = 7
 * There are no other valid combinations.
 *
 * Example 2:
 *
 *
 * Input: k = 3, n = 9
 * Output: [[1,2,6],[1,3,5],[2,3,4]]
 * Explanation:
 * 1 + 2 + 6 = 9
 * 1 + 3 + 5 = 9
 * 2 + 3 + 4 = 9
 * There are no other valid combinations.
 *
 *
 * Example 3:
 *
 *
 * Input: k = 4, n = 1
 * Output: []
 * Explanation: There are no valid combinations.
 * Using 4 different numbers in the range [1,9], the smallest sum we can get is
 * 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= k <= 9
 * 1 <= n <= 60
 *
 *
 */

#include "misc.h"
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  private:
    vector<vector<int>> result;

    void foo(int k, int n) {
        static vector<int> a;

        if (k == 0) {
            if (n == 0)
                result.push_back(a);
            return;
        }

        if (a.empty())
            for (int i = 1; i <= min(n, 9); i++) {
                a.push_back(i);
                foo(k - 1, n - i);
                a.pop_back();
            }
        else
            for (int i = a.back() + 1; i <= min(n, 9); i++) {
                a.push_back(i);
                foo(k - 1, n - i);
                a.pop_back();
            }
    }

  public:
    vector<vector<int>> combinationSum3(int k, int n) {
        foo(k, n);
        return result;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    // misc::printVec2D(Solution().combinationSum3(3, 9));
    misc::printVec2D(Solution().combinationSum3(4, 1));
    return 0;
}
