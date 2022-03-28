// 超时解决办法：1. 使用链表（减少erase操作的耗时） 2. 链表前向后向遍历（防止如[2,3,2,3,...,6]这样的样例）

/*
 * @lc app=leetcode id=2197 lang=cpp
 *
 * [2197] Replace Non-Coprime Numbers in Array
 *
 * https://leetcode.com/problems/replace-non-coprime-numbers-in-array/description/
 *
 * algorithms
 * Hard (34.01%)
 * Likes:    210
 * Dislikes: 6
 * Total Accepted:    6.8K
 * Total Submissions: 19.4K
 * Testcase Example:  '[6,4,3,2,7,6,2]'
 *
 * You are given an array of integers nums. Perform the following steps:
 *
 *
 * Find any two adjacent numbers in nums that are non-coprime.
 * If no such numbers are found, stop the process.
 * Otherwise, delete the two numbers and replace them with their LCM (Least
 * Common Multiple).
 * Repeat this process as long as you keep finding two adjacent non-coprime
 * numbers.
 *
 *
 * Return the final modified array. It can be shown that replacing adjacent
 * non-coprime numbers in any arbitrary order will lead to the same result.
 *
 * The test cases are generated such that the values in the final array are
 * less than or equal to 10^8.
 *
 * Two values x and y are non-coprime if GCD(x, y) > 1 where GCD(x, y) is the
 * Greatest Common Divisor of x and y.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [6,4,3,2,7,6,2]
 * Output: [12,7,6]
 * Explanation:
 * - (6, 4) are non-coprime with LCM(6, 4) = 12. Now, nums = [12,3,2,7,6,2].
 * - (12, 3) are non-coprime with LCM(12, 3) = 12. Now, nums = [12,2,7,6,2].
 * - (12, 2) are non-coprime with LCM(12, 2) = 12. Now, nums = [12,7,6,2].
 * - (6, 2) are non-coprime with LCM(6, 2) = 6. Now, nums = [12,7,6].
 * There are no more adjacent non-coprime numbers in nums.
 * Thus, the final modified array is [12,7,6].
 * Note that there are other ways to obtain the same resultant array.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [2,2,1,1,3,3,3]
 * Output: [2,1,1,3]
 * Explanation:
 * - (3, 3) are non-coprime with LCM(3, 3) = 3. Now, nums = [2,2,1,1,3,3].
 * - (3, 3) are non-coprime with LCM(3, 3) = 3. Now, nums = [2,2,1,1,3].
 * - (2, 2) are non-coprime with LCM(2, 2) = 2. Now, nums = [2,1,1,3].
 * There are no more adjacent non-coprime numbers in nums.
 * Thus, the final modified array is [2,1,1,3].
 * Note that there are other ways to obtain the same resultant array.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^5
 * The test cases are generated such that the values in the final array are
 * less than or equal to 10^8.
 *
 *
 */

#include "misc.h"
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start

#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <utility>

// GCD * LVM = A * B, LCM = A * B / GCD = A / GCD * B

class Solution {
  private:
    int gcd(int a, int b) {
        static map<pair<int, int>, int> dict;
        if (dict.find({min(a, b), max(a, b)}) == dict.end())
            dict[{min(a, b), max(a, b)}] = std::gcd(a, b);
        return dict[{min(a, b), max(a, b)}];
    }

    bool notDone(list<int> &nums_list) {
        for (auto i = nums_list.begin(); next(i) != nums_list.end(); i++) {
            if (gcd(*i, *next(i)) != 1) {
                return true;
            }
        }
        return false;
    }

  public:
    vector<int> replaceNonCoprimes(vector<int> &nums) {
        list<int> nums_list;
        copy(nums.begin(), nums.end(), std::back_inserter(nums_list));
        while (notDone(nums_list)) {
            for (auto i = nums_list.begin(); next(i) != nums_list.end();) {
                if (gcd(*i, *next(i)) != 1) {
                    *i = *i / gcd(*i, *next(i)) * *next(i);
                    nums_list.erase(next(i));
                } else
                    i++;
            }

            for (auto i = prev(nums_list.end()); prev(i) != nums_list.begin();) {
                if (gcd(*i, *prev(i)) != 1) {
                    *i = *i / gcd(*i, *prev(i)) * *prev(i);
                    nums_list.erase(prev(i));
                } else
                    i--;
            }
        }

        nums.clear();
        copy(nums_list.begin(), nums_list.end(), std::back_inserter(nums));
        return nums;
    }
};

// @lc code=end

int main(int argc, char const *argv[]) {
    // // [37,42701,47,31,13,2009]
    // vector<int> a = {37, 37, 37, 42701, 47, 31, 13, 2009};

    vector<int> a = {2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3};
    misc::printVec(Solution().replaceNonCoprimes(a));
    return 0;
}
