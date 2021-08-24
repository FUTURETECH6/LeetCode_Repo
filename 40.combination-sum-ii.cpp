/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (51.28%)
 * Likes:    3436
 * Dislikes: 97
 * Total Accepted:    444.9K
 * Total Submissions: 867.6K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sum to target.
 *
 * Each number in candidates may only be used once in the combination.
 *
 * Note: The solution set must not contain duplicate combinations.
 *
 *
 * Example 1:
 *
 *
 * Input: candidates = [10,1,2,7,6,1,5], target = 8
 * Output:
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input: candidates = [2,5,2,1,2], target = 5
 * Output:
 * [
 * [1,2,2],
 * [5]
 * ]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
#include <algorithm>
#include <functional>

class Solution {
  private:
    vector<vector<int>> result;

    void findCombination(vector<int>::iterator begin, vector<int>::iterator end,
        vector<int> &combination, int remainder) {
        if (remainder < 0) {  // Stop
            return;
        } else if (remainder == 0) {  // Found
            result.push_back(combination);
            return;
        } else {  // remainder > 0
            for (auto i = begin; i < end; i++) {
                if (i > begin           // **not skip first**
                    && *i == *(i - 1))  // skip dup
                    continue;
                combination.push_back(*i);
                findCombination(i + 1, end, combination, remainder - *i);
                combination.pop_back();
            }
        }
    }

  public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end(), less<int>());
        auto tmp = vector<int>(0);
        findCombination(candidates.begin(), candidates.end(), tmp, target);
        return result;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target             = 10;
    auto a                 = Solution().combinationSum2(candidates, target);
    return 0;
}

/*
这个要考虑重复comb的问题，例如 1 1 2 5 6 7 10 要凑 8
可以第一个1和7凑也可以第二个1和7凑，125也是同理会出现两次（116不会）

用上面这种方法，由于skip是从begin的下一个开始的，因此不会把有多个1在同一个comb里面的情况给剔除
例如有[1, 1, 1, 2, 3, 4]要凑5，可以[1a, 1b, 1c, 2], [1a, 1b, 3], [1a, 4]
[1a, 1c, 3]为什么进不来？
    因为当begin在1a的时候，i只能是1a，（排除了1a1c，同时由于1a必选，也排除了1b1c
    进入下一层递归，begin在1b，i只能是1b，
    进入下一层递归，begin在1c，i只能是1c，
    取得1112后，回到start在1b的递归，i继续往后变成2，不行，变成3，可以。。。
*/