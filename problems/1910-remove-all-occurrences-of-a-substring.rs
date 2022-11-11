// Solved 2022-11-11
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (50.00%)

impl Solution {
    pub fn remove_occurrences(s: String, part: String) -> String {
        let part = part.chars().collect::<Vec<_>>();
        let mut stack = s.chars().collect::<Vec<_>>();
        let mut stack_index = 0;
        for ch in s.chars() {
            stack[stack_index] = ch;
            stack_index += 1;
            if stack_index >= part.len() && stack[stack_index - part.len()..stack_index] == part {
                stack_index -= part.len();
            }
        }
        stack.into_iter().take(stack_index).collect()
    }
}
