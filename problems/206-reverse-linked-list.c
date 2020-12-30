// Solved 2020-12-30 10:40
// Runtime: 0 ms (100.00%)
// Memory Usage: 6.5 MB (56.17%)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head) {
    if (!head || !(head->next)) return head;
    struct ListNode* ans = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return ans;
}
