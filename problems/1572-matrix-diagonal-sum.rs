// Solved 2022-08-31
// Runtime: 0 ms (100.00%)
// Memory Usage: 2.2 MB (86.79%)

impl Solution {
    pub fn diagonal_sum(mat: Vec<Vec<i32>>) -> i32 {
        let n = mat.len();
        (0..n).fold(0, |res, i| res + mat[i][i] + mat[i][n - 1 - i])
            - if n % 2 == 1 { mat[n / 2][n / 2] } else { 0 }
    }
}
