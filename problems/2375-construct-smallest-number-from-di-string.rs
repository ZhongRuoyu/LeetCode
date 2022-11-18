// Solved 2022-11-18
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (100.00%)

impl Solution {
    pub fn smallest_number(pattern: String) -> String {
        let pattern = pattern.chars().collect::<Vec<_>>();
        let mut stack = Vec::new();
        let mut result = Vec::new();
        for i in 0..=pattern.len() {
            stack.push(char::from_u32('1' as u32 + i as u32).unwrap_or_default());
            if i == pattern.len() || pattern[i] == 'I' {
                stack.reverse();
                result.append(&mut stack);
            }
        }
        result.iter().collect()
    }
}
