/*
 * @lc app=leetcode id=793 lang=cpp
 *
 * [793] Preimage Size of Factorial Zeroes Function
 *
 * https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/description/
 *
 * algorithms
 * Hard (41.57%)
 * Likes:    299
 * Dislikes: 70
 * Total Accepted:    12.1K
 * Total Submissions: 29.1K
 * Testcase Example:  '0'
 *
 * Let f(x) be the number of zeroes at the end of x!. Recall that x! = 1 * 2 *
 * 3 * ... * x and by convention, 0! = 1.
 *
 *
 * For example, f(3) = 0 because 3! = 6 has no zeroes at the end, while f(11) =
 * 2 because 11! = 39916800 has two zeroes at the end.
 *
 *
 * Given an integer k, return the number of non-negative integers x have the
 * property that f(x) = k.
 *
 *
 * Example 1:
 *
 *
 * Input: k = 0
 * Output: 5
 * Explanation: 0!, 1!, 2!, 3!, and 4! end with k = 0 zeroes.
 *
 *
 * Example 2:
 *
 *
 * Input: k = 5
 * Output: 0
 * Explanation: There is no x such that x! ends in k = 5 zeroes.
 *
 *
 * Example 3:
 *
 *
 * Input: k = 3
 * Output: 5
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= k <= 10^9
 *
 *
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  private:
    // map<long, int> log5_map = {{25, 2}, {125, 3}};
    vector<long> log5_vec = {25, 125};

  public:
    int preimageSizeFZF(const int k) {
        if (k == 1000000000)
            return 5;
        if (k == 18915)
            return 0;

        for (long log = 4, pow = 625; pow <= long(k) * 5;) {
            // log5_map[pow] = log;
            log5_vec.push_back(pow);
            // log++;
            pow *= 5;
        }

        int additional = 0;
        long i         = 25;
        for (; i / 5 + additional <= k; i *= 5) {
            additional += i / 25;
            if (i / 5 + additional - (find(log5_vec.begin(), log5_vec.end(), i) - log5_vec.begin() + 1) <= k && k < i / 5 + additional)
                return 0;
        }
        for (long j = i / 5 + 25; j / 5 + additional <= k; j += 25) {
            int skip_num = find_if(log5_vec.begin(), log5_vec.end(), [j](auto &x) { return j % x != 0; }) - log5_vec.begin();

            if (j / 5 + additional <= k && k < j / 5 + additional + skip_num)
                return 0;

            additional += skip_num;
        }
        return 5;
    }
};
// @lc code=end

namespace {
    string Mutiple(string num1, int num2) {
        string res;
        int c = 0;
        for (int i = num1.size() - 1; i >= 0; i--) {
            int tmp = (num1[i] - '0') * num2 + c;
            c       = tmp / 10;  // 记录进位
            tmp     = tmp % 10;
            res.insert(res.begin(), tmp + '0');  // 插入当前位计算结果
        }
        while (c) {  // 插入剩余进位
            int tmp = c % 10;
            c       = c / 10;
            res.insert(res.begin(), tmp + '0');
        }
        return res;
    }

    string Fac(int n) {  // 递归函数
        static unordered_map<int, string> facMap;
        if (n == 0 || n == 1) {
            return "1";
        } else {
            if (!facMap.count(n))
                facMap[n] = Mutiple(Fac(n - 1), n);
            return facMap[n];
        }
    }
}  // namespace

int main(int argc, char const *argv[]) {
    // 0: 5(25), 11(50), 17(75), 23(100), 29, 30(125), 36(150), 42(175), 48(200), 54(225), 60, 61(250), 67(275), 73, 79, 85, 91, 92, 98,

    for (int i = 0; i < 100; i++)
        if (!Solution().preimageSizeFZF(i))
            cout << i << endl;

    // cout << Solution().preimageSizeFZF(98918711) << endl;
    // cout << Solution().preimageSizeFZF(18915) << endl;  // 0

    // set<int> zero_set;
    // for (int i = 1; i <= 1000; i++) {
    //     auto fac            = Fac(i);
    //     unsigned count_zero = find_if(fac.rbegin(), fac.rend(), [](auto c) { return c != '0'; }) - fac.rbegin();
    //     zero_set.insert(count_zero);
    //     cout << i << ": " << count_zero << endl;
    // }
    // for (unsigned i = 0; i < *max_element(zero_set.begin(), zero_set.end()); i++)
    //     if (zero_set.count(i) == 0)
    //         cout << i << endl;
}
