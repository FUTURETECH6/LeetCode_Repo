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

#include <numeric>
#include <set>
#include <unordered_map>

class Solution {
  private:
    unordered_map<int, set<vector<int> *>> stopRoutes;  // which stop has which routes(use `set<vector<int> *>` to represent)
    set<int> stops;
    unordered_map<int, unsigned> busToTake;

    void updateStop(int stop) {
        stops.erase(stop);
        for (auto &route : stopRoutes[stop]) {

            for (auto &iStop : *route) {
                if (busToTake.count(iStop) == 0)
                    busToTake[iStop] = busToTake[stop] + 1;
                else
                    busToTake[iStop] = min(busToTake[iStop], busToTake[stop] + 1);
            }
            for (auto &iStop : *route)
                if (stops.count(iStop) == 1)
                    updateStop(iStop);
        }
    }

  public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target) {

        for (auto &route : routes) {
            for (auto &stop : route) {
                stops.insert(stop);

                if (stopRoutes.count(stop) == 0)
                    stopRoutes[stop] = {&route};
                else
                    stopRoutes[stop].insert(&route);
            }
        }

        busToTake[source] = 0;
        updateStop(source);
        return busToTake.count(target) ? busToTake[target] : -1;
    }
};

// @lc code=end

int main(int argc, char const *argv[]) {
    vector<vector<int>> routes = {{1, 2, 7}, {3, 6, 7}};

    cout << Solution().numBusesToDestination(routes, 1, 6);
    return 0;
}
