/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (36.25%)
 * Likes:    5472
 * Dislikes: 312
 * Total Accepted:    880.8K
 * Total Submissions: 2.4M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given the head of a linked list, remove the n^th node from the end of the
 * list and return its head.
 *
 * Follow up: Could you do this in one pass?
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4,5], n = 2
 * Output: [1,2,3,5]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1], n = 1
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: head = [1,2], n = 1
 * Output: [1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is sz.
 * 1 <= sz <= 30
 * 0 <= Node.val <= 100
 * 1 <= n <= sz
 *
 *
 */

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
#include <vector>
#define USE_VECTOR 0

class Solution {
  public:
#if USE_VECTOR
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        vector<ListNode *> vec;
        for (auto p = head; p; p = p->next)
            vec.push_back(p);

        int id = vec.size() - n;

        if (vec.size() == 1) {  // Only one elem
            delete head;
            return nullptr;
        }

        // 2 or more elems
        if (id == 0) {  // First one
            delete head;
            return vec[1];
        } else if (id == vec.size() - 1) {  // Last one
            delete vec.back();
            (*(vec.end() - 2))->next = nullptr;
            return head;
        } else {
            vec[id - 1]->next = vec[id + 1];
            delete vec[id];
            return head;
        }
    }
#else
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *ret = head;
        int size      = 0;
        for (auto p = head; p; p = p->next)
            size++;
        int id = size - n;

        if (size == 1) {  // Only one elem
            delete head;
            return nullptr;
        }
        // 2 or more elems
        if (id == 0) {  // First one
            ret = head->next;
            delete head;
        } else if (id == size - 1) {  // Last one
            ListNode *p;
            for (p = head; p->next->next; p = p->next)
                ;  // p is the last 2nd one after loop
            delete p->next;
            p->next = nullptr;
        } else {
            ListNode *p = head;
            for (int i = 0; i < id - 1; i++)
                p = p->next;
            ListNode *tmpNext2nd = p->next->next;
            delete p->next;
            p->next = tmpNext2nd;
        }
        return ret;
    }
#endif
};
// @lc code=end
