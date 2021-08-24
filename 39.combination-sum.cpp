/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (61.55%)
 * Likes:    7117
 * Dislikes: 171
 * Total Accepted:    809K
 * Total Submissions: 1.3M
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given an array of distinct integers candidates and a target integer target,
 * return a list of all unique combinations of candidates where the chosen
 * numbers sum to target. You may return the combinations in any order.
 *
 * The same number may be chosen from candidates an unlimited number of times.
 * Two combinations are unique if the frequency of at least one of the chosen
 * numbers is different.
 *
 * It is guaranteed that the number of unique combinations that sum up to
 * target is less than 150 combinations for the given input.
 *
 *
 * Example 1:
 *
 *
 * Input: candidates = [2,3,6,7], target = 7
 * Output: [[2,2,3],[7]]
 * Explanation:
 * 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple
 * times.
 * 7 is a candidate, and 7 = 7.
 * These are the only two combinations.
 *
 *
 * Example 2:
 *
 *
 * Input: candidates = [2,3,5], target = 8
 * Output: [[2,2,2,2],[2,3,3],[3,5]]
 *
 *
 * Example 3:
 *
 *
 * Input: candidates = [2], target = 1
 * Output: []
 *
 *
 * Example 4:
 *
 *
 * Input: candidates = [1], target = 1
 * Output: [[1]]
 *
 *
 * Example 5:
 *
 *
 * Input: candidates = [1], target = 2
 * Output: [[1,1]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= candidates.length <= 30
 * 1 <= candidates[i] <= 200
 * All elements of candidates are distinct.
 * 1 <= target <= 500
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
        if (remainder < 0 || begin == end) {  // Stop
            return;
        } else if (remainder == 0) {  // Found
            result.push_back(combination);
            return;
        } else {  // remainder > 0
            if (*begin <= remainder) {
                combination.push_back(*begin);
                findCombination(begin, end, combination, remainder - *begin);
                combination.pop_back();
            }
            // Always need to move forward
            findCombination(begin + 1, end, combination, remainder);
        }
    }

  public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end(), less<int>());
        auto tmp = vector<int>(0);
        findCombination(candidates.begin(), candidates.end(), tmp, target);
        return result;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    vector<int> candidates = {2, 3, 5};
    int target             = 8;
    auto a                 = Solution().combinationSum(candidates, target);
    return 0;
}
