/*
 * @lc app=leetcode id=815 lang=cpp
 *
 * [815] Bus Routes
 *
 * https://leetcode.com/problems/bus-routes/description/
 *
 * algorithms
 * Hard (45.16%)
 * Likes:    1981
 * Dislikes: 51
 * Total Accepted:    82.7K
 * Total Submissions: 182.7K
 * Testcase Example:  '[[1,2,7],[3,6,7]]\n1\n6'
 *
 * You are given an array routes representing bus routes where routes[i] is a
 * bus route that the i^th bus repeats forever.
 *
 *
 * For example, if routes[0] = [1, 5, 7], this means that the 0^th bus travels
 * in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
 *
 *
 * You will start at the bus stop source (You are not on any bus initially),
 * and you want to go to the bus stop target. You can travel between bus stops
 * by buses only.
 *
 * Return the least number of buses you must take to travel from source to
 * target. Return -1 if it is not possible.
 *
 *
 * Example 1:
 *
 *
 * Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
 * Output: 2
 * Explanation: The best strategy is take the first bus to the bus stop 7, then
 * take the second bus to the bus stop 6.
 *
 *
 * Example 2:
 *
 *
 * Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target
 * = 12
 * Output: -1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= routes.length <= 500.
 * 1 <= routes[i].length <= 10^5
 * All the values of routes[i] are unique.
 * sum(routes[i].length) <= 10^5
 * 0 <= routes[i][j] < 10^6
 * 0 <= source, target < 10^6
 *
 *
 */

#include "misc.h"
using namespace std;

// @lc code=start

#include <deque>
#include <numeric>
#include <set>
#include <unordered_map>

class Solution {
  private:
    unordered_map<int, set<vector<int> *>> stopRoutesMap;  // which stop has which routes(use `set<vector<int> *>` to represent)
    unordered_map<int, unsigned> busToTakeMap;             // store result
    deque<int> stopQueue;                                  // queue for BFS
    unordered_map<vector<int> *, bool> isDone;             // which bus has been used

    void updateStop(int stop) {
        for (auto &pRoute : stopRoutesMap[stop]) {
            if (isDone[pRoute])
                continue;

            for (auto &iStop : *pRoute) {
                stopQueue.push_back(iStop);

                if (busToTakeMap.count(iStop) == 0)
                    busToTakeMap[iStop] = busToTakeMap[stop] + 1;
                else
                    busToTakeMap[iStop] = min(busToTakeMap[iStop], busToTakeMap[stop] + 1);
            }
            isDone[pRoute] = true;
        }
    }

  public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target) {
        for (auto &route : routes) {
            for (auto &stop : route) {
                if (stopRoutesMap.count(stop) == 0)
                    stopRoutesMap[stop] = {&route};
                else
                    stopRoutesMap[stop].insert(&route);
            }

            isDone[&route] = false;
        }

        busToTakeMap[source] = 0;
        stopQueue.push_back(source);
        while (!stopQueue.empty()) {
            updateStop(stopQueue.front());
            stopQueue.pop_front();
        }
        return busToTakeMap.count(target) ? busToTakeMap[target] : -1;
    }
};

// @lc code=end

int main(int argc, char const *argv[]) {
    vector<vector<int>> routes = {{1, 2, 7}, {3, 6, 7}};

    cout << Solution().numBusesToDestination(routes, 1, 6) << endl;
    return 0;
}
