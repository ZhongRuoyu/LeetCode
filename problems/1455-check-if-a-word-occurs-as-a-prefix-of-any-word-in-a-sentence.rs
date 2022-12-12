// Solved 2022-12-12
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (60.00%)

impl Solution {
    pub fn is_prefix_of_word(sentence: String, search_word: String) -> i32 {
        sentence
            .split(' ')
            .enumerate()
            .filter(|(_i, word)| word.starts_with(search_word.as_str()))
            .map(|(i, _word)| i as i32 + 1)
            .next()
            .unwrap_or(-1)
    }
}
