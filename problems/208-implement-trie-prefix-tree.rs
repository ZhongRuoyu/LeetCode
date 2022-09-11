// Solved 2022-09-11
// Runtime: 30 ms (69.93%)
// Memory Usage: 14.5 MB (45.45%)

struct Trie {
    root: TrieNode,
}

struct TrieNode {
    children: std::collections::HashMap<char, TrieNode>,
    is_leaf: bool,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Trie {
    fn new() -> Self {
        Trie {
            root: TrieNode::new(),
        }
    }

    fn insert(&mut self, word: String) {
        let char_vec: Vec<_> = word.chars().collect();
        self.root.insert(&char_vec)
    }

    fn search(&self, word: String) -> bool {
        let char_vec: Vec<_> = word.chars().collect();
        self.root.search(&char_vec)
    }

    fn starts_with(&self, prefix: String) -> bool {
        let char_vec: Vec<_> = prefix.chars().collect();
        self.root.starts_with(&char_vec)
    }
}

impl TrieNode {
    fn new() -> Self {
        TrieNode {
            children: std::collections::HashMap::new(),
            is_leaf: false,
        }
    }

    fn insert(&mut self, word: &[char]) {
        match word.first() {
            Some(ch) => {
                self.children
                    .entry(*ch)
                    .or_insert(TrieNode::new())
                    .insert(&word[1..]);
            }
            None => self.is_leaf = true,
        }
    }

    fn search(&self, word: &[char]) -> bool {
        match word.first() {
            Some(ch) => match self.children.get(ch) {
                Some(child) => child.search(&word[1..]),
                None => false,
            },
            None => self.is_leaf,
        }
    }

    fn starts_with(&self, prefix: &[char]) -> bool {
        match prefix.first() {
            Some(ch) => match self.children.get(ch) {
                Some(child) => child.starts_with(&prefix[1..]),
                None => false,
            },
            None => true,
        }
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * let obj = Trie::new();
 * obj.insert(word);
 * let ret_2: bool = obj.search(word);
 * let ret_3: bool = obj.starts_with(prefix);
 */
