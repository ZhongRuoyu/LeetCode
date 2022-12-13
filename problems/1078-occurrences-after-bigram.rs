// Solved 2022-12-13
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (100.00%)

impl Solution {
    pub fn find_ocurrences(text: String, first: String, second: String) -> Vec<String> {
        text.split(' ')
            .zip(text.split(' ').skip(1).zip(text.split(' ').skip(2)))
            .filter(|(word1, (word2, _word3))| {
                *word1 == first.as_str() && *word2 == second.as_str()
            })
            .map(|(_word1, (_word2, word3))| String::from(word3))
            .collect()
    }
}
