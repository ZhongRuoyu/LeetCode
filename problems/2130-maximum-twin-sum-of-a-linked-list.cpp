// Solved 2022-09-29
// Runtime: 319 ms (77.92%)
// Memory Usage: 116.7 MB (73.66%)

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
    int pairSum(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = reverse(slow);

        int result = 0;
        while (slow != nullptr) {
            result = max(result, head->val + slow->val);
            head = head->next;
            slow = slow->next;
        }

        return result;
    }

   private:
    ListNode *reverse(ListNode *head) {
        ListNode *curr = head;
        ListNode *prev = nullptr;
        while (curr != nullptr) {
            swap(curr->next, prev);
            if (prev == nullptr) {
                swap(curr, prev);
            } else {
                swap(prev->next, curr);
            }
        }
        return prev;
    }
};
