// Solved 2022-09-01
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (100.00%)

impl Solution {
    pub fn truncate_sentence(s: String, k: i32) -> String {
        let mut word = 0;
        for (i, ch) in s.chars().enumerate() {
            if ch == ' ' {
                word += 1;
                if word == k {
                    return s.chars().take(i).collect();
                }
            }
        }
        s
    }
}
