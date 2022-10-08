// Solved 2022-10-08
// Runtime: 3 ms (100.00%)
// Memory Usage: 2.3 MB (90.00%)

impl Solution {
    pub fn min_steps(s: String, t: String) -> i32 {
        let mut chars = vec![0; 26];
        s.chars().zip(t.chars()).for_each(|(s_char, t_char)| {
            chars[s_char as usize - 'a' as usize] += 1;
            chars[t_char as usize - 'a' as usize] -= 1;
        });
        chars.into_iter().filter(|x| *x > 0).sum()
    }
}
