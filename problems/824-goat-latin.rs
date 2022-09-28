// Solved 2022-09-28
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (100.00%)

impl Solution {
    pub fn to_goat_latin(sentence: String) -> String {
        sentence
            .split_ascii_whitespace()
            .into_iter()
            .enumerate()
            .map(|(i, word)| {
                let mut chars = word.chars().collect::<Vec<_>>();
                let first_char = chars[0].to_ascii_lowercase();
                if first_char != 'a'
                    && first_char != 'e'
                    && first_char != 'i'
                    && first_char != 'o'
                    && first_char != 'u'
                {
                    chars.rotate_left(1);
                }
                chars.push('m');
                chars.append(&mut vec!['a'; i + 2]);
                chars.into_iter().collect::<String>()
            })
            .collect::<Vec<_>>()
            .join(" ")
    }
}
