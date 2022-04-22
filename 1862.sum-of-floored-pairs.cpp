/*
 * @lc app=leetcode id=1862 lang=cpp
 *
 * [1862] Sum of Floored Pairs
 *
 * https://leetcode.com/problems/sum-of-floored-pairs/description/
 *
 * algorithms
 * Hard (27.76%)
 * Likes:    287
 * Dislikes: 24
 * Total Accepted:    5.9K
 * Total Submissions: 21K
 * Testcase Example:  '[2,5,9]'
 *
 * Given an integer array nums, return the sum of floor(nums[i] / nums[j]) for
 * all pairs of indices 0 <= i, j < nums.length in the array. Since the answer
 * may be too large, return it modulo 10^9 + 7.
 *
 * The floor() function returns the integer part of the division.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,5,9]
 * Output: 10
 * Explanation:
 * floor(2 / 5) = floor(2 / 9) = floor(5 / 9) = 0
 * floor(2 / 2) = floor(5 / 5) = floor(9 / 9) = 1
 * floor(5 / 2) = 2
 * floor(9 / 2) = 4
 * floor(9 / 5) = 1
 * We calculate the floor of the division for every pair of indices in the
 * array then sum them up.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [7,7,7,7,7,7,7]
 * Output: 49
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^5
 *
 *
 */

#include <iostream>
#include <vector>
using namespace std;
#include <chrono>

#define DEBUG

#include <cstdlib>

// @lc code=start

#include <algorithm>
#include <list>
#include <map>
#include <set>

class Solution {
  private:
    const int modulo = 1e9 + 7;

  public:
    int sumOfFlooredPairs(const vector<int> &nums) {
        int result = 0;

        //         map<int, unsigned, greater<int>> nums_map;

        // #ifdef DEBUG
        //         using namespace std::chrono;
        //         vector<int64_t> time;
        //         time.push_back(duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count());
        // #endif

        //         for (auto &num : nums)
        //             nums_map[num]++;
        //         auto nums_list = list<pair<int, unsigned>>(nums_map.begin(), nums_map.end());

        // #ifdef DEBUG
        //         time.push_back(duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count());
        //         cout << "[*] Time to get map and list: " << time.back() - *(time.end() - 2) << endl;
        // #endif

        //         while (!nums_list.empty()) {
        //             for (auto &pair : nums_list)
        //                 result = (result + (nums_list.front().second * pair.second) * (nums_list.front().first / pair.first)) % modulo;
        //             nums_list.pop_front();
        //         }

        // #ifdef DEBUG
        //         time.push_back(duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count());
        //         cout << "[*] Time to calculate result: " << time.back() - *(time.end() - 2) << endl;
        // #endif

        auto countVec = vector<unsigned>(1e+5 + 1, 0);
        set<int, less<>> numSet;

        for (auto &num : nums) {
            countVec[num]++;
            numSet.insert(num);
        }
        for (unsigned i = 1; i < countVec.size(); i++)
            countVec[i] += countVec[i - 1];
        auto max = *max_element(numSet.begin(), numSet.end());

        for (long num : numSet) {
            for (long x = num; x <= 1e+5 && x <= max; x += num) {
                // [x, x+num) ==> [x, x+num-1]
                if (countVec[min(x + num - 1, (long)1e+5)] != countVec[x - 1])
                    result = (result + (x / num) * (countVec[min(x + num - 1, (long)1e+5)] - countVec[x - 1]) * (countVec[num] - countVec[num - 1])) % modulo;
            }
        }

        return result;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    // vector<int> nums = {2, 5, 9};  // 10
    // vector<int> nums = {7, 7, 7, 7, 7, 7, 7};  // 49
    // vector<int> nums = {4, 3, 4, 3, 5};  // 17

    vector<int> nums;
    for (unsigned i = 0; i < 1e+5; i++)
        nums.push_back(rand() % int(1e+5 - 1) + 1);

    cout << Solution().sumOfFlooredPairs(nums) << endl;
    return 0;
}
