// Solved 2022-09-25
// Runtime: 0 ms (100.00%)
// Memory Usage: 2.1 MB (83.33%)

impl Solution {
    pub fn check_if_pangram(sentence: String) -> bool {
        let letters = <std::collections::HashSet<char> as std::iter::FromIterator<char>>::from_iter(
            sentence.chars(),
        );
        ('a'..='z').all(|letter| letters.contains(&letter))
    }
}
