// Solved 2022-12-14
// Runtime: 2 ms (82.35%)
// Memory Usage: 2.1 MB (88.24%)

impl Solution {
    pub fn min_operations(logs: Vec<String>) -> i32 {
        let mut level = 0;
        for log in logs {
            match log.as_str() {
                "../" => level = 0.max(level - 1),
                "./" => (),
                _ => level += 1,
            }
        }
        level
    }
}
