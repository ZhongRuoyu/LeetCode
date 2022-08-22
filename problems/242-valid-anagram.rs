// Solved 2022-08-22
// Runtime: 0 ms (100.00%)
// Memory Usage: 2.1 MB (99.73%)

impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        let mut letters = vec![0; 26];
        s.chars()
            .for_each(|ch| letters[ch as usize - 'a' as usize] += 1);
        t.chars()
            .for_each(|ch| letters[ch as usize - 'a' as usize] -= 1);
        letters.iter().all(|count| *count == 0)
    }
}
