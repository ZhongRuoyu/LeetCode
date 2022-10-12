// Solved 2022-10-12
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (100.00%)

impl Solution {
    pub fn remove_palindrome_sub(s: String) -> i32 {
        if s.is_empty() {
            0
        } else if s.chars().eq(s.chars().rev()) {
            1
        } else {
            2
        }
    }
}
