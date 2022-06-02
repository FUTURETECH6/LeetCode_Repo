/*
 * @lc app=leetcode id=1792 lang=cpp
 *
 * [1792] Maximum Average Pass Ratio
 *
 * https://leetcode.com/problems/maximum-average-pass-ratio/description/
 *
 * algorithms
 * Medium (50.41%)
 * Likes:    482
 * Dislikes: 58
 * Total Accepted:    14.9K
 * Total Submissions: 29.4K
 * Testcase Example:  '[[1,2],[3,5],[2,2]]\n2'
 *
 * There is a school that has classes of students and each class will be having
 * a final exam. You are given a 2D integer array classes, where classes[i] =
 * [passi, totali]. You know beforehand that in the i^th class, there are
 * totali total students, but only passi number of students will pass the
 * exam.
 *
 * You are also given an integer extraStudents. There are another extraStudents
 * brilliant students that are guaranteed to pass the exam of any class they
 * are assigned to. You want to assign each of the extraStudents students to a
 * class in a way that maximizes the average pass ratio across all the
 * classes.
 *
 * The pass ratio of a class is equal to the number of students of the class
 * that will pass the exam divided by the total number of students of the
 * class. The average pass ratio is the sum of pass ratios of all the classes
 * divided by the number of the classes.
 *
 * Return the maximum possible average pass ratio after assigning the
 * extraStudents students. Answers within 10^-5 of the actual answer will be
 * accepted.
 *
 *
 * Example 1:
 *
 *
 * Input: classes = [[1,2],[3,5],[2,2]], extraStudents = 2
 * Output: 0.78333
 * Explanation: You can assign the two extra students to the first class. The
 * average pass ratio will be equal to (3/4 + 3/5 + 2/2) / 3 = 0.78333.
 *
 *
 * Example 2:
 *
 *
 * Input: classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4
 * Output: 0.53485
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= classes.length <= 10^5
 * classes[i].length == 2
 * 1 <= passi <= totali <= 10^5
 * 1 <= extraStudents <= 10^5
 *
 *
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start

#include <algorithm>
#include <list>
#include <numeric>
#include <queue>

#define USE_HEAP

class Solution {
  private:
    double diff(vector<int> &c) {
        auto &a = c[0], &b = c[1];
        return double(b - a) / double(b) / double(b + 1);
    }

  public:
    // acc: (a + x) / (b + x) > a / b
    // \frac{a + 1}{b + 1} - \frac{a}{b} = \frac{b - a}{b * (b + 1)}
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents) {
#ifdef USE_HEAP
        auto comp = [&](auto &c1, auto &c2) { return diff(*c1) < diff(*c2); };
        priority_queue<vector<int> *, vector<vector<int> *>, decltype(comp)> classes_heap(comp);
        for (auto &i : classes)
            classes_heap.push(&i);
#endif

        for (; extraStudents; extraStudents--) {
#ifdef USE_HEAP
            auto top = classes_heap.top();
            classes_heap.pop();
            top->at(0)++;
            top->at(1)++;
            classes_heap.push(top);
#else
            auto tarClass = max_element(classes.begin(), classes.end(), [&](auto &c1, auto &c2) { return diff(c1) < diff(c2); });

            tarClass->at(0)++;
            tarClass->at(1)++;
#endif
        }

        return accumulate(classes.begin(), classes.end(), double(0), [](double &res, auto &c) { return res + double(c[0]) / double(c[1]); }) / classes.size();
    }
};

// @lc code=end
int main(int argc, char const *argv[]) {
    // vector<vector<int>> classes = {{1, 2}, {3, 5}, {2, 2}};
    // cout << Solution().maxAverageRatio(classes, 2) << endl;

    vector<vector<int>> classes = {{2, 4}, {3, 9}, {4, 5}, {2, 10}};
    cout << Solution().maxAverageRatio(classes, 4) << endl;
    return 0;
}
