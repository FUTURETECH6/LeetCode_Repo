/*
 * @lc app=leetcode id=2183 lang=cpp
 *
 * [2183] Count Array Pairs Divisible by K
 *
 * https://leetcode.com/problems/count-array-pairs-divisible-by-k/description/
 *
 * algorithms
 * Hard (26.19%)
 * Likes:    392
 * Dislikes: 21
 * Total Accepted:    7.6K
 * Total Submissions: 28.8K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a 0-indexed integer array nums of length n and an integer k, return
 * the number of pairs (i, j) such that:
 *
 *
 * 0 <= i < j <= n - 1 and
 * nums[i] * nums[j] is divisible by k.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3,4,5], k = 2
 * Output: 7
 * Explanation:
 * The 7 pairs of indices whose corresponding products are divisible by 2 are
 * (0, 1), (0, 3), (1, 2), (1, 3), (1, 4), (2, 3), and (3, 4).
 * Their products are 2, 4, 6, 8, 10, 12, and 20 respectively.
 * Other pairs such as (0, 2) and (2, 4) have products 3 and 15 respectively,
 * which are not divisible by 2.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3,4], k = 5
 * Output: 0
 * Explanation: There does not exist any pair of indices whose corresponding
 * product is divisible by 5.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i], k <= 10^5
 *
 *
 */

#include "misc.h"
using namespace std;

// @lc code=start

#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
#include <set>
#include <unordered_map>
#include <utility>

class Solution {
  private:
    // auto getPrimeFactor(int k) {
    //     static vector<int> prime_number = {2, 3, 5, 7, 11, 13};
    //     multiset<int> prime_factors;

    //     auto sqrt_k = sqrt(k);

    //     if (prime_number.back() < sqrt_k) {
    //         for (auto i = prime_number.back() + 2; i <= sqrt_k; i += 2) {
    //             // i is odd and >= 9
    //             bool prime = true;
    //             for (int j = 3; j <= sqrt(i); j += 2) {
    //                 if (i % j == 0) {
    //                     prime = false;
    //                     break;
    //                 }
    //             }
    //             if (prime)
    //                 prime_number.push_back(i);
    //         }
    //     }

    //     for (auto i : prime_number)
    //         if (i > sqrt(k))
    //             break;
    //         else
    //             while (k % i == 0) {
    //                 k /= i;
    //                 prime_factors.insert(i);
    //             }

    //     if (k != 1)
    //         prime_factors.insert(k);

    //     return prime_factors;
    // }

    template <class T>
    T gcd(T a, T b) {
        // static map<pair<T, T>, T> dict;
        // if (dict.find({min(a, b), max(a, b)}) == dict.end())
        //     dict[{min(a, b), max(a, b)}] = std::gcd(a, b);
        // return dict[{min(a, b), max(a, b)}];

        return b > 0 ? gcd(b, a % b) : a;
    }

  public:
    long long countPairs(vector<int> &nums, const int k) {
        // auto prime_factor_k      = getPrimeFactor(k);
        // long long multiple_count = 0;

        // for (auto i = nums.begin(); i != nums.end();) {  // 去除k的倍数并计算
        //     if (*i % k == 0) {
        //         multiple_count++;
        //         nums.erase(i);
        //     } else
        //         i++;
        // }

        // long long count = multiple_count * nums.size()                  // all multiple factors * other
        //                   + multiple_count * (multiple_count - 1) / 2;  // C(|multiple factors|, 2)

        // for (auto i = nums.begin(); i != nums.end();) {  // 去除和k没有质因数的（不可能构成pair，除非另一个数是k本身，但是这种情况在前面倍数中已经被排除了）
        //     auto prime_factor_i = getPrimeFactor(*i);
        //     vector<int> intersection;

        //     set_intersection(prime_factor_i.begin(), prime_factor_i.end(), prime_factor_k.begin(), prime_factor_k.end(), back_inserter(intersection));

        //     if (intersection.size() == 0) {
        //         nums.erase(i);
        //     } else
        //         i++;
        // }

        // for (auto i = nums.begin(); i < nums.end(); i++) {
        //     for (auto j = i + 1; j < nums.end(); j++) {
        //         if ((long)*i * (long)*j % k == 0)
        //             count++;
        //     }
        // }

        long long allCount = 0;
        unordered_map<long, long long> gcdMap;

        for (auto &i : nums) {
            long gcd_i_k = gcd(i, k);
            for (auto &[gcd_j_k, count] : gcdMap) {
                if (gcd_i_k * gcd_j_k % k == 0) {
                    allCount += count;
                }
            }
            gcdMap[gcd_i_k]++;
        }

        return allCount;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    // vector<int> nums = {1, 2, 3, 4, 5};
    // int k            = 2;

    // [1, 2, 1892, 21, 43, 22, 123, 213, 12, 24, 89, 3, 4, 5]\n6
    vector<int> nums = {1, 2, 1892, 21, 43, 22, 123, 213, 12, 24, 89, 3, 4, 5};
    int k            = 6;

    cout << Solution().countPairs(nums, k) << endl;

    // auto prime_factors = Solution().getPrimeFactor(36);
    // for (auto i : prime_factors)
    //     cout << i << ": " << prime_factors.count(i) << endl;

    return 0;
}
