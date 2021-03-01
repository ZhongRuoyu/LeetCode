// Solved 2021-03-01 11:51
// Runtime: 40 ms (84.42%)
// Memory Usage: 14.3 MB (95.78%)

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *x = headA, *y = headB;
        while (x != y) {
            x = x ? x->next : headB;
            y = y ? y->next : headA;
        }
        return x;
    }
};

/**
 * # Explanation
 * 
 * ## If the intersection exists
 * 
 * Denote listA by (x -> c),
 *    and listB by (y -> c),
 * where the lengths of x and y are not necessarily the same.
 * 
 * Then (listA -> listB) is (x -> c -> y -> c),
 *  and (listB -> listA) is (y -> c -> x -> c).
 * 
 * Note that length(x -> c -> y) == length (y -> c -> x).
 * Then we can get the intersection, if not in the first pass, then in the second.
 * 
 * ## If the intersection does not exist
 * 
 * (x -> y) and (y -> x) do not intersect at all.
 */
