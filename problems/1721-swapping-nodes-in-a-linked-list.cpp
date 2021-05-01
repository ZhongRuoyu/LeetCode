// Solved 2021-05-01 08:17
// Runtime: 560 ms (95.62%)
// Memory Usage: 180.1 MB (84.50%)

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
    ListNode *swapNodes(ListNode *head, int k) {
        ListNode *fast = head, *r = head, *l = head;
        for (int i = 1; i < k; ++i) {
            fast = fast->next;
            l = l->next;
        }
        while (fast->next) {
            fast = fast->next;
            r = r->next;
        }
        swap(l->val, r->val);
        return head;
    }
};
