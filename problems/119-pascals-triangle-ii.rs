// Solved 2022-08-18
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (95.33%)

impl Solution {
    pub fn get_row(row_index: i32) -> Vec<i32> {
        let mut result = vec![0; (row_index + 1) as usize];
        result[0] = 1;
        for i in 1..row_index + 1 {
            for j in (1..i + 1).rev() {
                result[j as usize] += result[(j - 1) as usize];
            }
        }
        result
    }
}
