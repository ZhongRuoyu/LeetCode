// Solved 2022-09-08
// Runtime: 7 ms (73.61%)
// Memory Usage: 2.2 MB (98.61%)

impl Solution {
    pub fn largest_local(grid: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let n = grid.len();
        let mut result = vec![vec![0; n - 2]; n - 2];
        for result_i in 0..n - 2 {
            for result_j in 0..n - 2 {
                for grid_i in result_i..result_i + 3 {
                    for grid_j in result_j..result_j + 3 {
                        result[result_i][result_j] =
                            std::cmp::max(result[result_i][result_j], grid[grid_i][grid_j]);
                    }
                }
            }
        }
        result
    }
}
