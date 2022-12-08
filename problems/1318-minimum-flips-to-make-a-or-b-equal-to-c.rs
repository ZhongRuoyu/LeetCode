// Solved 2022-12-08
// Runtime: 0 ms (100.00%)
// Memory Usage: 1.9 MB (100.00%)

impl Solution {
    pub fn min_flips(a: i32, b: i32, c: i32) -> i32 {
        (0..32)
            .map(|x| {
                if (c >> x) & 1 == 0 {
                    ((a >> x) & 1) + ((b >> x) & 1)
                } else {
                    (((a >> x) & 1) | ((b >> x) & 1)) ^ 1
                }
            })
            .sum()
    }
}
