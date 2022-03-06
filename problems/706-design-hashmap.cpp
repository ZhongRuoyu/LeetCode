// Solved 2022-03-06
// Runtime: 128 ms (85.98%)
// Memory Usage: 54.2 MB (64.48%)

class MyHashMap {
    const size_t SIZE = 256;

    struct Node {
        int key;
        int value;
        shared_ptr<Node> next;
    };

    vector<shared_ptr<Node>> lookup_;

    size_t hash(int key) {
        return key % SIZE;
    }

    shared_ptr<Node> get_node(int key) {
        size_t bucket = hash(key);
        for (auto node = lookup_[bucket]; node != nullptr; node = node->next) {
            if (node->key == key) {
                return node;
            }
        }
        return nullptr;
    }

   public:
    MyHashMap() : lookup_(SIZE) {}

    void put(int key, int value) {
        auto node = get_node(key);
        if (node != nullptr) {
            node->value = value;
        } else {
            size_t bucket = hash(key);
            lookup_[bucket] = make_shared<Node>(
                (Node){.key = key, .value = value, .next = lookup_[bucket]});
        }
    }

    int get(int key) {
        auto node = get_node(key);
        return node != nullptr ? node->value : -1;
    }

    void remove(int key) {
        size_t bucket = hash(key);
        auto dummy = make_shared<Node>(
            (Node){.key = 0, .value = 0, .next = lookup_[bucket]});
        for (auto node = dummy; node->next != nullptr; node = node->next) {
            if (node->next->key == key) {
                if (node->next == lookup_[bucket]) {
                    lookup_[bucket] = node->next->next;
                } else {
                    node->next = node->next->next;
                }
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
