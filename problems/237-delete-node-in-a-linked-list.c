// Solved 2020-12-11 09:16
// Runtime: 4 ms (95.32%)
// Memory Usage: 6.3 MB (99.87%)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void deleteNode(struct ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}
