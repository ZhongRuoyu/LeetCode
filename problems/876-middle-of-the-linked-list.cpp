// Solved 2021-12-17
// Runtime: 0 ms (100.00%)
// Memory Usage: 7.1 MB (70.29%)

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
    ListNode *middleNode(ListNode *head) {
        ListNode *p = head, *middle = head;
        for (int i = 0; p->next; ++i) {
            if (i % 2 == 0) middle = middle->next;
            p = p->next;
        }
        return middle;
    }
};
