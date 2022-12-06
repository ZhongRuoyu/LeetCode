// Solved 2022-12-06
// Runtime: 0 ms (100.00%)
// Memory Usage: 2.1 MB (92.86%)

impl Solution {
    pub fn number_of_lines(widths: Vec<i32>, s: String) -> Vec<i32> {
        let mut line_count = 1;
        let mut line_width = 0;
        for ch in s.chars() {
            let width = widths[ch as usize - 'a' as usize];
            if line_width + width > 100 {
                line_count += 1;
                line_width = width;
            } else {
                line_width += width;
            }
        }
        vec![line_count, line_width]
    }
}
