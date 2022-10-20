// Solved 2022-10-20
// Runtime: 14 ms (85.00%)
// Memory Usage: 2.6 MB (95.00%)

impl Solution {
    pub fn count_squares(matrix: Vec<Vec<i32>>) -> i32 {
        let m = matrix.len();
        let n = matrix[0].len();
        let mut dp = matrix;
        let mut count = 0;
        for i in 0..m {
            for j in 0..n {
                if dp[i][j] != 0 && i > 0 && j > 0 {
                    dp[i][j] = 1 + std::cmp::min(
                        dp[i - 1][j - 1],
                        std::cmp::min(dp[i - 1][j], dp[i][j - 1]),
                    );
                }
                count += dp[i][j];
            }
        }
        count
    }
}

// See also: Problem 221 (Maximal Square)
