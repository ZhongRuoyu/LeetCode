// Solved 2021-03-10 09:12
// Runtime: 0 ms (100.00%)
// Memory Usage: 10.1 MB (94.17%)

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
    ListNode *partition(ListNode *head, int x) {
        ListNode *p = head,
                 *less = new ListNode(), *lessHead = less,
                 *greater = new ListNode(), *greaterHead = greater;
        while (p) {
            if (p->val < x) {
                less = less->next = p;
            } else {
                greater = greater->next = p;
            }
            p = p->next;
        }
        less->next = greaterHead->next;
        greater->next = nullptr;
        p = lessHead->next;
        delete lessHead;
        delete greaterHead;
        return p;
    }
};
