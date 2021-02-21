// Solved 2021-02-21 13:03
// Runtime: 8 ms (93.33%)
// Memory Usage: 11.5 MB (95.98%)

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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *p = head, *nodeToDelete;
        while (p) {
            while (p->next && p->val == p->next->val) {
                nodeToDelete = p->next;
                p->next = p->next->next;
                delete nodeToDelete;
            }
            p = p->next;
        }
        return head;
    }
};

// See also: Problem 82 (Remove Duplicates from Sorted List II)
