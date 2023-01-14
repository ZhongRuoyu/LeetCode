// Solved 2023-01-14
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (92.76%)

impl Solution {
    pub fn detect_capital_use(word: String) -> bool {
        let word = word.chars().collect::<Vec<_>>();
        if word[0].is_uppercase() {
            word.iter().skip(1).all(|ch| ch.is_uppercase())
                || word.iter().skip(1).all(|ch| ch.is_lowercase())
        } else {
            word.into_iter().all(|ch| ch.is_lowercase())
        }
    }
}
