// Solved 2022-09-22
// Runtime: 72 ms (100.00%)
// Memory Usage: 3.4 MB (62.50%)

impl Solution {
    pub fn restore_matrix(row_sum: Vec<i32>, col_sum: Vec<i32>) -> Vec<Vec<i32>> {
        let mut row_sum = row_sum;
        let mut col_sum = col_sum;
        let mut matrix = vec![vec![0; col_sum.len()]; row_sum.len()];
        for (i, row) in matrix.iter_mut().enumerate() {
            for (j, element) in row.iter_mut().enumerate() {
                *element = std::cmp::min(row_sum[i], col_sum[j]);
                row_sum[i] -= *element;
                col_sum[j] -= *element;
            }
        }
        matrix
    }
}
