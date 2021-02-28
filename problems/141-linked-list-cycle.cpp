// Solved 2021-02-28 11:36
// Runtime: 4 ms (99.29%)
// Memory Usage: 7.9 MB (34.92%)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
   public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) return true;
        }
        return false;
    }
};

// Wait, but this is supposed to be much less memory-consuming...
