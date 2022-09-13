// Solved 2022-09-13
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (100.00%)

impl Solution {
    pub fn sort_sentence(s: String) -> String {
        let mut words = s
            .split_whitespace()
            .map(|word| {
                (
                    word[..word.len() - 1].to_string(),
                    word[word.len() - 1..].parse::<i32>().unwrap_or_default(),
                )
            })
            .collect::<Vec<_>>();
        words.sort_unstable_by_key(|x| x.1);
        words
            .iter()
            .map(|word| word.0.as_str())
            .collect::<Vec<_>>()
            .join(" ")
    }
}
