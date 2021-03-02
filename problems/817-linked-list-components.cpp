// Solved 2021-03-02 18:26
// Runtime: 28 ms (97.56%)
// Memory Usage: 21.3 MB (80.08%)

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
    int numComponents(ListNode *head, vector<int> &G) {
        int res = 0;
        // a hash map is much more efficient than a vector
        unordered_set<int> lookup(G.begin(), G.end());
        ListNode *l = head, *r;
        while (l) {
            if (lookup.count(l->val) == 0) {
                l = l->next;
                continue;
            }
            r = l->next;
            while (r && lookup.count(r->val)) r = r->next;
            ++res;
            l = r;
        }
        return res;
    }
};
