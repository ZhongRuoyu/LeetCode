// Solved 2022-10-18
// Runtime: 5 ms (75.00%)
// Memory Usage: 2.3 MB (75.00%)

impl Solution {
    pub fn matrix_block_sum(mat: Vec<Vec<i32>>, k: i32) -> Vec<Vec<i32>> {
        let m = mat.len();
        let n = mat[0].len();

        let mut prefix_sum = vec![vec![0; n]; m];
        prefix_sum[0][0] = mat[0][0];
        (1..m).for_each(|i| prefix_sum[i][0] = prefix_sum[i - 1][0] + mat[i][0]);
        (1..n).for_each(|j| prefix_sum[0][j] = prefix_sum[0][j - 1] + mat[0][j]);
        for i in 1..m {
            for j in 1..n {
                prefix_sum[i][j] = prefix_sum[i - 1][j] + prefix_sum[i][j - 1]
                    - prefix_sum[i - 1][j - 1]
                    + mat[i][j];
            }
        }

        let mut result = vec![vec![0; n]; m];
        for i in 0..m {
            for j in 0..n {
                let i_lower = std::cmp::max(0, i as i32 - k) as usize;
                let i_upper = std::cmp::min(m as i32 - 1, i as i32 + k) as usize;
                let j_lower = std::cmp::max(0, j as i32 - k) as usize;
                let j_upper = std::cmp::min(n as i32 - 1, j as i32 + k) as usize;
                result[i][j] = prefix_sum[i_upper][j_upper];
                if i_lower > 0 {
                    result[i][j] -= prefix_sum[i_lower - 1][j_upper];
                }
                if j_lower > 0 {
                    result[i][j] -= prefix_sum[i_upper][j_lower - 1];
                }
                if i_lower > 0 && j_lower > 0 {
                    result[i][j] += prefix_sum[i_lower - 1][j_lower - 1];
                }
            }
        }

        result
    }
}
