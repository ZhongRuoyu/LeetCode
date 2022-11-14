// Solved 2022-11-14
// Runtime: 16 ms (87.50%)
// Memory Usage: 3.5 MB (87.50%)

impl Solution {
    pub fn largest_combination(candidates: Vec<i32>) -> i32 {
        (0..32)
            .map(|x| {
                candidates
                    .iter()
                    .filter(|&candidate| candidate & (1 << x) != 0)
                    .count() as i32
            })
            .max()
            .unwrap_or_default()
    }
}
