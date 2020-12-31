// Solved 2020-12-31 10:07
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.8 MB (99.40%)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* swapPairs(struct ListNode* head) {
    if (!head) return head;
    struct ListNode *result = head->next ? head->next : head,
                    *t;
    while (head && head->next) {
        t = head->next->next;
        head->next->next = head;
        head->next = (t && t->next) ? t->next : t;
        head = t;
    }
    return result;
}
