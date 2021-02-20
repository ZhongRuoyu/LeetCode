// Solved 2021-02-20 09:22
// Runtime: 4 ms (98.27%)
// Memory Usage: 11.1 MB (88.69%)

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
        ListNode *nodeToDelete;
        while (head && head->next && head->val == head->next->val) {
            while (head->next && head->val == head->next->val) {
                nodeToDelete = head->next;
                head->next = head->next->next;
                delete nodeToDelete;
            }
            nodeToDelete = head;
            head = head->next;
            delete nodeToDelete;
        }
        if (head == nullptr) return head;
        ListNode *p = head->next, *prev = head;
        while (p) {
            if (p->next && p->val == p->next->val) {
                while (p->next && p->val == p->next->val) {
                    nodeToDelete = p->next;
                    p->next = p->next->next;
                    delete nodeToDelete;
                }
                nodeToDelete = p;
                prev->next = p = p->next;
                delete nodeToDelete;
            } else {
                prev = p;
                p = p->next;
            }
        }
        return head;
    }
};

// See also: Problem 83 (Remove Duplicates from Sorted List)
