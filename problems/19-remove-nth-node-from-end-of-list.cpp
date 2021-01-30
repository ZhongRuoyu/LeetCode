// Solved 2021-01-30 10:38
// Runtime: 0 ms (100.00%)
// Memory Usage: 10.6 MB (87.20%)

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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *l = head, *r = head,
                 *nodeToDelete;
        for (int i = 0; i < n; ++i) r = r->next;
        if (r == nullptr) {
            nodeToDelete = head;
            head = head->next;
            delete nodeToDelete;
            return head;
        }
        while (r->next) {
            l = l->next, r = r->next;
        }
        nodeToDelete = l->next;
        l->next = l->next->next;
        delete nodeToDelete;
        return head;
    }
};
