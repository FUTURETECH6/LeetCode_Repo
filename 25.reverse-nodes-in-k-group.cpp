/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (45.96%)
 * Likes:    3807
 * Dislikes: 403
 * Total Accepted:    356.5K
 * Total Submissions: 775.5K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 *
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes, in the end, should remain as it is.
 *
 * You may not alter the values in the list's nodes, only nodes themselves may
 * be changed.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4,5], k = 2
 * Output: [2,1,4,3,5]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,2,3,4,5], k = 3
 * Output: [3,2,1,4,5]
 *
 *
 * Example 3:
 *
 *
 * Input: head = [1,2,3,4,5], k = 1
 * Output: [1,2,3,4,5]
 *
 *
 * Example 4:
 *
 *
 * Input: head = [1], k = 1
 * Output: [1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range sz.
 * 1 <= sz <= 5000
 * 0 <= Node.val <= 1000
 * 1 <= k <= sz
 *
 *
 *
 * Follow-up: Can you solve the problem in O(1) extra memory space?
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
/*
1 -> 2 -> 3 -> 4 -> 5

1 <- 2    3 -> 4 ->5
|              ^
+--------------+

1 <- 2 <- 3    4 ->5
|              ^
+--------------+
*/

class Solution {
  public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k < 2)
            return head;

        auto const last = getLast(head, k);

        if (!last)  // List length not enough
            return head;

        auto const last_next = last->next;

        for (auto p = head, nd = head->next, rd = nd->next; nd != last_next;
             p = nd, nd = rd, rd = rd ? rd->next : nullptr)
            nd->next = p;

        head->next = reverseKGroup(last_next, k);
        return last;
    }

  private:
    ListNode *getLast(ListNode *&p, int k) {  // 1 2 3 4, k = 3 will return 3
        return k > 1 ? (p ? getLast(p->next, k - 1) : nullptr) : p;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    head           = Solution().reverseKGroup(head, 1);
    return 0;
}
