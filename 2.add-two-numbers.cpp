/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (35.96%)
 * Likes:    11790
 * Dislikes: 2794
 * Total Accepted:    1.9M
 * Total Submissions: 5.4M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order, and each of their nodes
 * contains a single digit. Add the two numbers and return the sum as a linked
 * list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 *
 * Example 1:
 *
 *
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [7,0,8]
 * Explanation: 342 + 465 = 807.
 *
 *
 * Example 2:
 *
 *
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
 *
 *
 * Example 3:
 *
 *
 * Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * Output: [8,9,9,9,0,0,0,1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in each linked list is in the range [1, 100].
 * 0 <= Node.val <= 9
 * It is guaranteed that the list represents a number that does not have
 * leading zeros.
 *
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        bool carry    = 0;
        ListNode *ret = new ListNode(0), *result = ret;
        while ((l1 || l2) || carry) {
            int thisNum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry       = thisNum > 9;
            result->val = thisNum - carry * 10;
            l1          = l1 ? l1->next : l1;
            l2          = l2 ? l2->next : l2;
            result = result->next = (l1 || l2) || carry ? new ListNode(0) : nullptr;
        }
        return ret;
    }
};
// @lc code=end

/*
Possible Improvement
时间：
内存：直接利用其中原有的链子的空间去存储。开始是先用l1的，如果l1比l2短，就在l1结束后把next接到l2的当前node，然后继续。全程唯一需要新分配的空间只有《最高位进位》的情况下分配的一个node。
*/