/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (56.69%)
 * Likes:    6907
 * Dislikes: 784
 * Total Accepted:    1.4M
 * Total Submissions: 2.5M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a sorted list. The list
 * should be made by splicing together the nodes of the first two lists.
 *
 *
 * Example 1:
 *
 *
 * Input: l1 = [1,2,4], l2 = [1,3,4]
 * Output: [1,1,2,3,4,4]
 *
 *
 * Example 2:
 *
 *
 * Input: l1 = [], l2 = []
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: l1 = [], l2 = [0]
 * Output: [0]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in both lists is in the range [0, 50].
 * -100 <= Node.val <= 100
 * Both l1 and l2 are sorted in non-decreasing order.
 *
 *
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
using namespace std;

class Solution {
  public:
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

// class Solution {
//   public:
//     ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
//         if (!l1)
//             return l2;
//         if (!l2)
//             return l1;
//         ListNode *pCur = nullptr, *p1 = l1, *p2 = l2;
//         if (l1->val < l2->val) {
//             pCur = l1;
//             p1   = p1->next;
//         } else {
//             pCur = l2;
//             p2   = p2->next;
//         }
//         for (; p1 && p2; pCur = pCur->next) {
//             if (p1->val < p2->val) {
//                 pCur->next = p1;
//                 p1         = p1->next;
//             } else {
//                 pCur->next = p2;
//                 p2         = p2->next;
//             }
//         }
//         if (!p1)
//             pCur->next = p2;
//         if (!p2)
//             pCur->next = p1;
//         return l1->val < l2->val ? l1 : l2;
//     }
// };

// class Solution {
//   public:
//     ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
//         if (!l1)
//             return l2;
//         if (!l2)
//             return l1;
//         ListNode *ret = nullptr;
//         auto p1 = l1, p2 = l2, p = ret;
//         for (; p1 && p2;) {
//             if (ret)
//                 p = p->next = new ListNode;
//             else
//                 ret = p = new ListNode;
//             if (p1->val < p2->val) {
//                 p->val = p1->val;
//                 p1     = p1->next;
//             } else {
//                 p->val = p2->val;
//                 p2     = p2->next;
//             }
//         }
//         if (!p1)
//             p->next = p2;
//         if (!p2)
//             p->next = p1;
//         return ret;
//     }
// };