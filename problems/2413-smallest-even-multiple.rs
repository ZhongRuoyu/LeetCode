// Solved 2022-09-30
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (94.51%)

impl Solution {
    pub fn smallest_even_multiple(n: i32) -> i32 {
        n * (n % 2 + 1)
    }
}
