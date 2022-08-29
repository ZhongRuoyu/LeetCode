// Solved 2022-08-29
// Runtime: 4 ms (100.00%)
// Memory Usage: 2.2 MB (100.00%)

impl Solution {
    pub fn get_last_moment(n: i32, left: Vec<i32>, right: Vec<i32>) -> i32 {
        std::cmp::max(
            left.iter().map(|i| *i).max().unwrap_or_default(),
            right.iter().map(|i| n - *i).max().unwrap_or_default(),
        )
    }
}
