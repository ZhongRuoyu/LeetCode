// Solved 2023-01-18
// Runtime: 3 ms (84.31%)
// Memory Usage: 2.1 MB (94.12%)

impl Solution {
    pub fn similar_pairs(words: Vec<String>) -> i32 {
        let mut lookup = std::collections::HashMap::new();
        let mut count = 0;
        for word in words {
            let mut bits = 0i32;
            for ch in word.chars() {
                bits |= 1 << (ch as u32 - 'a' as u32);
            }
            lookup
                .entry(bits)
                .and_modify(|c| {
                    count += *c;
                    *c += 1;
                })
                .or_insert(1);
        }
        count
    }
}
