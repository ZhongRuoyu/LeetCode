// Solved 2023-01-13
// Runtime: 0 ms (100.00%)
// Memory Usage: 2.3 MB (84.00%)

impl Solution {
    pub fn find_relative_ranks(score: Vec<i32>) -> Vec<String> {
        let mut indices = (0..score.len()).collect::<Vec<_>>();
        indices.sort_unstable_by_key(|i| -score[*i]);
        let mut result = vec![String::new(); score.len()];
        indices.into_iter().enumerate().for_each(|(rank, i)| {
            result[i] = match rank + 1 {
                1 => String::from("Gold Medal"),
                2 => String::from("Silver Medal"),
                3 => String::from("Bronze Medal"),
                n => n.to_string(),
            }
        });
        result
    }
}
