// Solved 2022-01-14
// Runtime: 424 ms (63.86%)
// Memory Usage: 167 MB (58.97%)

class LRUCache {
    struct Node {
        int key;
        int value;
        shared_ptr<Node> next;
        shared_ptr<Node> prev;

        Node(int key, int value)
            : key(key), value(value), next(nullptr), prev(nullptr) {}
    };

    int capacity_;
    int size_;
    shared_ptr<Node> head_;
    shared_ptr<Node> tail_;
    unordered_map<int, shared_ptr<Node>> lookup_;

    int touch(int key) {
        shared_ptr<Node> entry = lookup_[key];
        entry->prev->next = entry->next;
        entry->next->prev = entry->prev;
        entry->next = head_->next;
        entry->next->prev = entry;
        entry->prev = head_;
        entry->prev->next = entry;
        return entry->value;
    }

    void push_front(int key, int value) {
        auto entry = make_shared<Node>(key, value);
        entry->next = head_->next;
        entry->next->prev = entry;
        entry->prev = head_;
        entry->prev->next = entry;
        lookup_[key] = entry;
        ++size_;
    }

    void pop_back() {
        auto entry = tail_->prev;
        if (entry == head_) {
            return;
        }
        entry->prev->next = entry->next;
        entry->next->prev = entry->prev;
        lookup_.erase(entry->key);
        --size_;
    }

   public:
    LRUCache(int capacity)
        : capacity_(capacity),
          size_(0),
          head_(make_shared<Node>(0, 0)),
          tail_(make_shared<Node>(0, 0)),
          lookup_() {
        head_->next = tail_;
        tail_->prev = head_;
    }

    int get(int key) {
        return lookup_.count(key) ? touch(key) : -1;
    }

    void put(int key, int value) {
        if (lookup_.count(key)) {
            touch(key);
            head_->next->value = value;
        } else {
            push_front(key, value);
            if (size_ > capacity_) {
                pop_back();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
