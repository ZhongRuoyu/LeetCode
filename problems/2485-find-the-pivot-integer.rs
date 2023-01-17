// Solved 2023-01-17
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (97.50%)

impl Solution {
    pub fn pivot_integer(n: i32) -> i32 {
        let sum = n * (n + 1) / 2;
        let pivot = (sum as f64).sqrt() as i32;
        if pivot * pivot == sum {
            pivot
        } else {
            -1
        }
    }
}
