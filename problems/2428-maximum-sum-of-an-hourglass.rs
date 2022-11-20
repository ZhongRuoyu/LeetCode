// Solved 2022-11-20
// Runtime: 5 ms (73.47%)
// Memory Usage: 2.3 MB (79.59%)

impl Solution {
    pub fn max_sum(grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let mut max = 0;
        for i in 0..(m - 2) {
            for j in 0..(n - 2) {
                let curr = grid[i][j]
                    + grid[i][j + 1]
                    + grid[i][j + 2]
                    + grid[i + 1][j + 1]
                    + grid[i + 2][j]
                    + grid[i + 2][j + 1]
                    + grid[i + 2][j + 2];
                max = std::cmp::max(max, curr);
            }
        }
        max
    }
}
