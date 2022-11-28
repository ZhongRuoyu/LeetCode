// Solved 2022-11-28
// Runtime: 0 ms (100.00%)
// Memory Usage: 2.1 MB (84.21%)

impl Solution {
    pub fn common_chars(words: Vec<String>) -> Vec<String> {
        let mut common = vec![usize::MAX; 26];
        for word in words {
            let mut letters = vec![0; 26];
            for char in word.chars() {
                letters[char as usize - 'a' as usize] += 1;
            }
            common
                .iter_mut()
                .zip(letters.iter())
                .for_each(|(x, &y)| *x = (*x).min(y))
        }
        common
            .into_iter()
            .enumerate()
            .flat_map(|(letter, count)| {
                std::iter::repeat(
                    String::from_utf8(vec!['a' as u8 + letter as u8]).unwrap_or_default(),
                )
                .take(count)
            })
            .collect()
    }
}
