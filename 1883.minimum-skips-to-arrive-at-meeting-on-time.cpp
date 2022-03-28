/*
 * @lc app=leetcode id=1883 lang=cpp
 *
 * [1883] Minimum Skips to Arrive at Meeting On Time
 *
 * https://leetcode.com/problems/minimum-skips-to-arrive-at-meeting-on-time/description/
 *
 * algorithms
 * Hard (38.67%)
 * Likes:    205
 * Dislikes: 39
 * Total Accepted:    4.4K
 * Total Submissions: 11.5K
 * Testcase Example:  '[1,3,2]\n4\n2'
 *
 * You are given an integer hoursBefore, the number of hours you have to travel
 * to your meeting. To arrive at your meeting, you have to travel through n
 * roads. The road lengths are given as an integer array dist of length n,
 * where dist[i] describes the length of the i^th road in kilometers. In
 * addition, you are given an integer speed, which is the speed (in km/h) you
 * will travel at.
 *
 * After you travel road i, you must rest and wait for the next integer hour
 * before you can begin traveling on the next road. Note that you do not have
 * to rest after traveling the last road because you are already at the
 * meeting.
 *
 *
 * For example, if traveling a road takes 1.4 hours, you must wait until the 2
 * hour mark before traveling the next road. If traveling a road takes exactly
 * 2 hours, you do not need to wait.
 *
 *
 * However, you are allowed to skip some rests to be able to arrive on time,
 * meaning you do not need to wait for the next integer hour. Note that this
 * means you may finish traveling future roads at different hour marks.
 *
 *
 * For example, suppose traveling the first road takes 1.4 hours and traveling
 * the second road takes 0.6 hours. Skipping the rest after the first road will
 * mean you finish traveling the second road right at the 2 hour mark, letting
 * you start traveling the third road immediately.
 *
 *
 * Return the minimum number of skips required to arrive at the meeting on
 * time, or -1 if it is impossible.
 *
 *
 * Example 1:
 *
 *
 * Input: dist = [1,3,2], speed = 4, hoursBefore = 2
 * Output: 1
 * Explanation:
 * Without skipping any rests, you will arrive in (1/4 + 3/4) + (3/4 + 1/4) +
 * (2/4) = 2.5 hours.
 * You can skip the first rest to arrive in ((1/4 + 0) + (3/4 + 0)) + (2/4) =
 * 1.5 hours.
 * Note that the second rest is shortened because you finish traveling the
 * second road at an integer hour due to skipping the first rest.
 *
 *
 * Example 2:
 *
 *
 * Input: dist = [7,3,5,5], speed = 2, hoursBefore = 10
 * Output: 2
 * Explanation:
 * Without skipping any rests, you will arrive in (7/2 + 1/2) + (3/2 + 1/2) +
 * (5/2 + 1/2) + (5/2) = 11.5 hours.
 * You can skip the first and third rest to arrive in ((7/2 + 0) + (3/2 + 0)) +
 * ((5/2 + 0) + (5/2)) = 10 hours.
 *
 *
 * Example 3:
 *
 *
 * Input: dist = [7,3,5,5], speed = 1, hoursBefore = 10
 * Output: -1
 * Explanation: It is impossible to arrive at the meeting on time even if you
 * skip all the rests.
 *
 *
 *
 * Constraints:
 *
 *
 * n == dist.length
 * 1 <= n <= 1000
 * 1 <= dist[i] <= 10^5
 * 1 <= speed <= 10^6
 * 1 <= hoursBefore <= 10^7
 *
 *
 */

#include "misc.h"
#include <vector>
using namespace std;

// @lc code=start

#include <algorithm>
#include <numeric>

class Solution {
  private:
    unsigned long roundTo(unsigned long a, unsigned long b) { return a % b == 0 ? a : (a / b) * b + b; }

  public:
    int minSkips(vector<int> &dist, int speed, int hoursBefore) {
        // !! important: prevent overflow
        const unsigned long initValue = -1 - speed - *max_element(dist.begin(), dist.end());

        auto dp = vector<vector<unsigned long>>(dist.size());  // dp[i][j]: min time(in speed * time) after no.i road with j skips (last rest not included)
        for (auto i = 0; i < dist.size(); i++)
            dp[i].resize(i + 2, initValue);

        dp[0][0] = dist[0];
        for (auto i = 1; i < dist.size(); i++) {
            dp[i][0] = roundTo(dp[i - 1][0], speed) + dist[i];
            for (auto j = 1; j <= i; j++) {
                dp[i][j] = min(dp[i - 1][j - 1] + dist[i], roundTo(dp[i - 1][j], speed) + dist[i]);
            }
        }

        for (auto i = 0; i < dist.size(); i++)
            if (dp.back()[i] <= (unsigned long)hoursBefore * (unsigned long)speed)
                return i;
        return -1;
    }
};

// @lc code=end

int main(int argc, char const *argv[]) {
    vector<int> arr = {7, 3, 5, 5};
    cout << Solution().minSkips(arr, 2, 10) << endl;
    return 0;
}

// int minSkips(vector<int> &dist, int speed, int hoursBefore) {
//     if (accumulate(dist.begin(), dist.end(), .0) / double(speed) > hoursBefore)
//         return -1;

//     vector<double> walk, rest;
//     for (auto &i : dist) {
//         walk.push_back((double)i / (double)speed);
//         rest.push_back(1 - (walk.back() - i / speed));
//     }
//     rest.back() = 0;

//     sort(rest.begin(), rest.end(), greater<double>());

//     int minSkips    = 0;
//     double leftTime = accumulate(walk.begin(), walk.end(), (double).0) + accumulate(rest.begin(), rest.end(), (double).0) - hoursBefore;
//     for (auto &i : rest) {
//         if (leftTime <= 0)
//             break;
//         leftTime -= i;
//         minSkips++;
//     }

//     return minSkips;
// }
