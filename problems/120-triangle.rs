// Solved 2022-08-19
// Runtime: 0 ms (100.00%)
// Memory Usage: 2.2 MB (100.00%)

impl Solution {
    pub fn minimum_total(triangle: Vec<Vec<i32>>) -> i32 {
        let mut minimum = triangle.last().unwrap_or(&vec![]).clone();
        for i in (0..triangle.len() - 1).rev() {
            for j in 0..i + 1 {
                minimum[j] = std::cmp::min(minimum[j], minimum[j + 1]) + triangle[i][j];
            }
        }
        minimum[0]
    }
}
