// Solved 2021-02-13 18:56
// Runtime: 20 ms (91.78%)
// Memory Usage: 15.1 MB (62.77%)

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
    ListNode *removeElements(ListNode *head, int val) {
        if (head == nullptr) return head;
        ListNode *nodeToDelete;
        while (head->val == val && head->next) {
            nodeToDelete = head;
            head = head->next;
            delete nodeToDelete;
        }
        if (head->val == val) {
            delete head;
            return nullptr;
        }
        ListNode *p = head, *prev = head;
        while (p = p->next) {
            if (p->val == val) {
                nodeToDelete = p;
                prev->next = p->next;
                delete nodeToDelete;
                p = prev;
            } else {
                prev = prev->next;
            }
        }
        return head;
    }
};
