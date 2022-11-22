// Solved 2022-11-22
// Runtime: 4 ms (96.15%)
// Memory Usage: 2.2 MB (100.00%)

impl Solution {
    pub fn letter_case_permutation(s: String) -> Vec<String> {
        let mut s = s.chars().collect();
        let mut result = Vec::new();
        Self::dfs(&mut result, &mut s, 0);
        result
    }

    fn dfs(result: &mut Vec<String>, s: &mut Vec<char>, index: usize) {
        if index == s.len() {
            result.push(s.iter().collect());
            return;
        }
        Self::dfs(result, s, index + 1);
        let saved = s[index];
        if saved.is_alphabetic() {
            s[index] = if saved.is_uppercase() {
                saved.to_ascii_lowercase()
            } else {
                saved.to_ascii_uppercase()
            };
            Self::dfs(result, s, index + 1);
            s[index] = saved;
        }
    }
}
