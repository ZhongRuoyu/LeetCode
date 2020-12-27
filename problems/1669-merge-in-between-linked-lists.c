// Solved 2020-12-27 10:51
// Runtime: 140 ms (40.22%)
// Memory Usage: 32.9 MB (93.48%)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2) {
    struct ListNode *p = list1, *ans = list1;
    int i = 0;
    for (; i < a - 1; i++) {
        p = p->next;
    }
    struct ListNode* end = p;
    for (; i < b + 1; i++) {
        end = end->next;
    }
    while (list2) {
        p->next = list2;
        p = p->next;
        list2 = list2->next;
    }
    p->next = end;
    return ans;
}
