// Solved 2022-11-05
// Runtime: 2 ms (87.50%)
// Memory Usage: 2 MB (87.50%)

impl Solution {
    pub fn max_depth_after_split(seq: String) -> Vec<i32> {
        seq.chars()
            .into_iter()
            .enumerate()
            .fold(Vec::new(), |mut acc, (i, ch)| {
                acc.push(match ch {
                    '(' => i as i32 % 2,
                    ')' => (i + 1) as i32 % 2,
                    _ => 0,
                });
                acc
            })
    }
}
