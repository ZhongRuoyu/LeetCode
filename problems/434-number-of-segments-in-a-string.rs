// Solved 2022-08-20
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (91.67%)

impl Solution {
    pub fn count_segments(s: String) -> i32 {
        s.split(' ').filter(|str| !str.is_empty()).count() as i32
    }
}
