// Solved 2022-10-07
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (90.00%)

impl Solution {
    pub fn find_the_winner(n: i32, k: i32) -> i32 {
        (1..=n).fold(0, |prev, curr| (prev + k) % curr) + 1
    }
}
