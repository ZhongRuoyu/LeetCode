// Solved 2022-10-19
// Runtime: 32 ms (84.75%)
// Memory Usage: 9.4 MB (69.49%)

impl Solution {
    pub fn maximal_square(matrix: Vec<Vec<char>>) -> i32 {
        let m = matrix.len();
        let n = matrix[0].len();

        let mut dp = vec![vec![0; n]; m];
        (0..m).for_each(|i| dp[i][0] = if matrix[i][0] == '0' { 0 } else { 1 });
        (0..n).for_each(|j| dp[0][j] = if matrix[0][j] == '0' { 0 } else { 1 });

        let mut max_side = 0;
        for i in 0..m {
            for j in 0..n {
                if matrix[i][j] != '0' && i > 0 && j > 0 {
                    dp[i][j] = 1 + std::cmp::min(
                        dp[i - 1][j - 1],
                        std::cmp::min(dp[i - 1][j], dp[i][j - 1]),
                    );
                }
                max_side = std::cmp::max(max_side, dp[i][j]);
            }
        }

        max_side * max_side
    }
}

// See also: Problem 1277 (Count Square Submatrices with All Ones)
