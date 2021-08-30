/*
 * 回文子序列，例如"bccb"中有 b c c b bb cc bc1b bc2b bccb 9个（不去重）
 * 本题仅考虑奇数长度的
 */

#include "misc.h"
#include <iostream>
#include <string>
using namespace std;
// @code=start
#include <vector>

class Solution {
  private:
    using type       = int;
    const int modulo = 1e9 + 7;

  public:
    int countPalindromicSubsequences(string str) {
        int len = str.length();
        vector<vector<type>> dp(len, vector<type>(len, 0));

        for (int j = 0; j < len; j++) {  // tail
            dp[j][j] = 1;
            for (int i = j - 1; i >= 0; i--) {  // head
                dp[i][j] = str[i] == str[j]
                               ? dp[i + 1][j] + dp[i][j - 1]  // 如果没有奇数要求要+1
                               : modulo + dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
                dp[i][j] %= modulo;
            }
        }
        misc::printVec2D(dp);
        return dp[0][len - 1] % modulo;
    }
};
// @code=end

int main(int argc, char const *argv[]) {
    cout << Solution().countPalindromicSubsequences("bccb");
    return 0;
}
