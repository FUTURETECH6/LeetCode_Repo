/*
 * @lc app=leetcode id=2171 lang=cpp
 *
 * [2171] Removing Minimum Number of Magic Beans
 *
 * https://leetcode.com/problems/removing-minimum-number-of-magic-beans/description/
 *
 * algorithms
 * Medium (40.82%)
 * Likes:    439
 * Dislikes: 25
 * Total Accepted:    13.7K
 * Total Submissions: 33.5K
 * Testcase Example:  '[4,1,6,5]'
 *
 * You are given an array of positive integers beans, where each integer
 * represents the number of magic beans found in a particular magic bag.
 *
 * Remove any number of beans (possibly none) from each bag such that the
 * number of beans in each remaining non-empty bag (still containing at least
 * one bean) is equal. Once a bean has been removed from a bag, you are not
 * allowed to return it to any of the bags.
 *
 * Return the minimum number of magic beans that you have to remove.
 *
 *
 * Example 1:
 *
 *
 * Input: beans = [4,1,6,5]
 * Output: 4
 * Explanation:
 * - We remove 1 bean from the bag with only 1 bean.
 * ⁠ This results in the remaining bags: [4,0,6,5]
 * - Then we remove 2 beans from the bag with 6 beans.
 * ⁠ This results in the remaining bags: [4,0,4,5]
 * - Then we remove 1 bean from the bag with 5 beans.
 * ⁠ This results in the remaining bags: [4,0,4,4]
 * We removed a total of 1 + 2 + 1 = 4 beans to make the remaining non-empty
 * bags have an equal number of beans.
 * There are no other solutions that remove 4 beans or fewer.
 *
 *
 * Example 2:
 *
 *
 * Input: beans = [2,10,3,2]
 * Output: 7
 * Explanation:
 * - We remove 2 beans from one of the bags with 2 beans.
 * ⁠ This results in the remaining bags: [0,10,3,2]
 * - Then we remove 2 beans from the other bag with 2 beans.
 * ⁠ This results in the remaining bags: [0,10,3,0]
 * - Then we remove 3 beans from the bag with 3 beans.
 * ⁠ This results in the remaining bags: [0,10,0,0]
 * We removed a total of 2 + 2 + 3 = 7 beans to make the remaining non-empty
 * bags have an equal number of beans.
 * There are no other solutions that removes 7 beans or fewer.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= beans.length <= 10^5
 * 1 <= beans[i] <= 10^5
 *
 *
 */

#include "misc.h"
#include <vector>
using namespace std;

// @lc code=start

/*
 * for (auto &i : beans)
 *     result += i < target ? i : i - target;
 * // euqal
 * for (auto &i : beans)
 *     result += i - (i >= target ? target : 0);
 */

#include <algorithm>
#include <map>
#include <numeric>

class Solution {
  public:
    long long minimumRemoval(vector<int> &beans) {
        map<int, unsigned> count_map;
        for (auto &i : beans)
            count_map[i] = count_map.count(i) == 1 ? count_map[i] + 1 : 1;

        auto count_vec = vector<pair<int, unsigned>>(count_map.begin(), count_map.end());
        sort(count_vec.begin(), count_vec.end(), [](pair<int, unsigned> &a, pair<int, unsigned> &b) -> bool { return a.first > b.first; });

        long long subval    = 0;
        long long sum_count = 0;

        for (auto itor_target = count_vec.begin(); itor_target < count_vec.end(); itor_target++) {
            sum_count += itor_target->second;
            subval = max(subval, itor_target->first * sum_count);
        }

        return accumulate(beans.begin(), beans.end(), 0ll) - subval;
    }
};

// @lc code=end

int main(int argc, char const *argv[]) {
    // vector<int> a = {4, 1, 6, 5};
    vector<int> a = {66, 90, 47, 25, 92, 90, 76, 85, 22, 3};
    cout << Solution().minimumRemoval(a) << endl;
    return 0;
}
