// Solved 2022-04-09
// Runtime: 828 ms (90.70%)
// Memory Usage: 558.6 MB (60.69%)

class WordDictionary {
   private:
    struct TrieNode {
        // unfortunately std::shared_ptr is too slow...
        array<TrieNode *, 26> children{};
        bool is_leaf = false;

        ~TrieNode() {
            for (auto &child : children) {
                delete child;
            }
        }
    };

    TrieNode *root;

   public:
    WordDictionary() {
        this->root = new TrieNode();
    }

    void addWord(string word) {
        auto node = root;
        for (size_t i = 0; i < word.size(); ++i) {
            auto next = node->children[word[i] - 'a'];
            if (next == nullptr) {
                node->children[word[i] - 'a'] = next = new TrieNode();
            }
            node = next;
        }
        node->is_leaf = true;
    }

    bool search(string word) {
        return search(word, 0, root);
    }

   private:
    bool search(const string &word, size_t pos, TrieNode *node) {
        while (pos < word.size() && node != nullptr) {
            if (!islower(word[pos])) {
                for (auto &next : node->children) {
                    if (next != nullptr && search(word, pos + 1, next)) {
                        return true;
                    }
                }
                return false;
            }
            auto next = node->children[word[pos] - 'a'];
            if (next == nullptr) {
                return false;
            }
            node = next;
            ++pos;
        }
        return pos == word.size() && node != nullptr && node->is_leaf;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
