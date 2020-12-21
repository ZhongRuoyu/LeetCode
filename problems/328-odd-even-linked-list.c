// Solved 2020-12-22 07:32
// Runtime: 4 ms (92.40%)
// Memory Usage: 6.9 MB (80.80%)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* oddEvenList(struct ListNode* head) {
    if (!head || !head->next) return head;
    struct ListNode *odd = head, *even = head->next,
                    *oddHead = odd, *evenHead = even;
    head = head->next->next;
    for (int i = 2; head; i++) {
        if (i % 2) {
            even = even->next = head;
        } else {
            odd = odd->next = head;
        }
        head = head->next;
    }
    odd->next = evenHead;
    even->next = (struct ListNode*)NULL;
    return oddHead;
}
