// Solved 2022-12-10
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (97.60%)

impl Solution {
    pub fn is_circular_sentence(sentence: String) -> bool {
        sentence
            .split(' ')
            .zip(sentence.split(' ').cycle().skip(1))
            .all(|(prev, next)| prev.ends_with(next.chars().next().unwrap_or_default()))
    }
}
