// Solved 2022-11-09
// Runtime: 0 ms (100.00%)
// Memory Usage: 2.1 MB (100.00%)

impl Solution {
    pub fn min_flips(target: String) -> i32 {
        let mut prev = '0';
        let mut flips = 0;
        for ch in target.chars() {
            if ch != prev {
                flips += 1;
            }
            prev = ch;
        }
        flips
    }
}
