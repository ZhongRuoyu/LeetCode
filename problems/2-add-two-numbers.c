// Solved 2020-12-05 10:40
// Runtime: 4 ms (99.84%)
// Memory Usage: 7.7 MB (58.54%)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *x = (struct ListNode*)malloc(sizeof(struct ListNode)),
                    *head = x, *p;
    int sum, carry = 0;
    while (l1 && l2) {
        sum = l1->val + l2->val + carry;
        x->val = sum % 10;
        carry = sum / 10;
        l1 = l1->next;
        l2 = l2->next;
        x->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        p = x;
        x = x->next;
    }
    if (l2) l1 = l2;
    while (l1) {
        sum = l1->val + carry;
        x->val = sum % 10;
        carry = sum / 10;
        l1 = l1->next;
        x->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        p = x;
        x = x->next;
    }
    if (x->val = carry) {
        x->next = (struct ListNode*)NULL;
    } else {
        free(p->next);
        p->next = (struct ListNode*)NULL;
    }
    return head;
}
