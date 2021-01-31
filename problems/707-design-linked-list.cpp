// Solved 2021-01-31 12:11
// Runtime: 40 ms (88.78%)
// Memory Usage: 19.4 MB (97.90%)

class MyListNode {
   public:
    int val;
    MyListNode *next;
    MyListNode(int val = 0, MyListNode *next = nullptr) {
        this->val = val;
        this->next = next;
    }
};

class MyLinkedList {
   public:
    /** Initialize your data structure here. */
    MyLinkedList(MyListNode *head = nullptr) {
        this->head = head;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        MyListNode *p = head;
        while (index--) {
            if (p) {
                p = p->next;
            } else {
                return -1;
            }
        }
        return p ? p->val : -1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        MyListNode *p = new MyListNode(val);
        p->next = head;
        head = p;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if (head == nullptr) {
            head = new MyListNode(val);
            return;
        }
        MyListNode *p = head;
        while (p->next) p = p->next;
        p->next = new MyListNode(val);
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index < 0) return;
        if (index == 0) {
            addAtHead(val);
            return;
        }
        MyListNode *p = head;
        while (--index) {
            if (p) {
                p = p->next;
            } else {
                return;
            }
        }
        if (p == nullptr) return;
        MyListNode *nodeToAdd = new MyListNode(val);
        if (p->next) {
            nodeToAdd->next = p->next;
        }
        p->next = nodeToAdd;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || head == nullptr) return;
        MyListNode *nodeToDelete;
        if (index == 0) {
            nodeToDelete = head;
            head = head->next;
            delete nodeToDelete;
            return;
        }
        MyListNode *p = head;
        while (--index) {
            if (p) {
                p = p->next;
            } else {
                return;
            }
        }
        if (p == nullptr || p->next == nullptr) return;
        nodeToDelete = p->next;
        p->next = p->next->next;
        delete nodeToDelete;
    }

   private:
    MyListNode *head;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
