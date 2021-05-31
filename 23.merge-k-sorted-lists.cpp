/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (43.48%)
 * Likes:    7336
 * Dislikes: 358
 * Total Accepted:    893.5K
 * Total Submissions: 2.1M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * You are given an array of k linked-lists lists, each linked-list is sorted
 * in ascending order.
 *
 * Merge all the linked-lists into one sorted linked-list and return it.
 *
 *
 * Example 1:
 *
 *
 * Input: lists = [[1,4,5],[1,3,4],[2,6]]
 * Output: [1,1,2,3,4,4,5,6]
 * Explanation: The linked-lists are:
 * [
 * ⁠ 1->4->5,
 * ⁠ 1->3->4,
 * ⁠ 2->6
 * ]
 * merging them into one sorted list:
 * 1->1->2->3->4->4->5->6
 *
 *
 * Example 2:
 *
 *
 * Input: lists = []
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: lists = [[]]
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * k == lists.length
 * 0 <= k <= 10^4
 * 0 <= lists[i].length <= 500
 * -10^4 <= lists[i][j] <= 10^4
 * lists[i] is sorted in ascending order.
 * The sum of lists[i].length won't exceed 10^4.
 *
 *
 */
#include <vector>
using namespace std;

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start

class Solution {
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) {
            return nullptr;
        }
        while (lists.size() > 1) {
            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }

  private:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
// @lc code=end
class Solution {
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *pCur         = findMinAndFwd(lists);
        ListNode *const result = pCur;

        for (; pCur; pCur = pCur->next) {
            auto pMin = findMinAndFwd(lists);
            if (pMin) {
                pCur->next = pMin;
            } else
                break;
        }
        return result;
    }

  private:
    ListNode *&findMinAndFwd(vector<ListNode *> &lists) {
        int min                              = __INT_MAX__;
        vector<ListNode *>::iterator itorMin = lists.end();
        // ListNode *pMin = nullptr;
        for (auto list = lists.begin(); list < lists.end(); list++)
            if (*list && (*list)->val < min) {
                min     = (*list)->val;
                itorMin = list;
            }
        auto result = itorMin != lists.end() ? *itorMin : nullptr;
        if (itorMin != lists.end() && *itorMin)
            *itorMin = (*itorMin)->next;
        return result;
    }
};