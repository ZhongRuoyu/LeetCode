// Solved 2022-11-13
// Runtime: 10 ms (100.00%)
// Memory Usage: 2.6 MB (90.91%)

impl Solution {
    pub fn min_steps(s: String, t: String) -> i32 {
        let mut s_chars = vec![0; 26];
        let mut t_chars = vec![0; 26];
        s.chars().for_each(|ch| {
            s_chars[ch as usize - 'a' as usize] += 1;
        });
        t.chars().for_each(|ch| {
            t_chars[ch as usize - 'a' as usize] += 1;
        });
        s_chars
            .into_iter()
            .zip(t_chars.into_iter())
            .map(|(s_count, t_count)| i32::abs(s_count - t_count))
            .sum()
    }
}
