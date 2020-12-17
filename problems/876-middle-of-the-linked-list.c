// Solved 2020-12-17 09:14
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.7 MB (66.51%)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode *p = head, *middle = head;
    int i;
    for (i = 0; p->next; i++) {
        if (i % 2 == 0) middle = middle->next;
        p = p->next;
    }
    return middle;
}
