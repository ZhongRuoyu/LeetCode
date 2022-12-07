// Solved 2022-12-07
// Runtime: 0 ms (100.00%)
// Memory Usage: 2.1 MB (93.33%)

impl Solution {
    pub fn uncommon_from_sentences(s1: String, s2: String) -> Vec<String> {
        let mut word_count = std::collections::HashMap::new();
        [&s1, &s2].iter().for_each(|sentence| {
            sentence.split(' ').for_each(|word| {
                word_count
                    .entry(word)
                    .and_modify(|count| *count += 1)
                    .or_insert(1);
            });
        });
        word_count
            .into_iter()
            .filter(|(_word, count)| *count == 1)
            .map(|(word, _count)| String::from(word))
            .collect()
    }
}
