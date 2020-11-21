// Solved 2020-11-21 11:22
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.6 MB (78.77%)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int getDecimalValue(struct ListNode* head) {
    int r = 0;
    while (head) {
        r = (r << 1) + head->val;
        head = head->next;
    }
    return r;
}
