// Solved 2021-03-23 08:48
// Runtime: 4 ms (86.76%)
// Memory Usage: 7.3 MB (71.59%)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
   public:
    Node *flatten(Node *head) {
        stack<Node *> st;
        Node *p = head;
        while (p) {
            if (p->child) {
                if (p->next) st.push(p->next);
                p->next = p->child;
                p->next->prev = p;
                p->child = nullptr;
            } else if (p->next == nullptr && !st.empty()) {
                p->next = st.top();
                p->next->prev = p;
                st.pop();
            }
            p = p->next;
        }
        return head;
    }
};
