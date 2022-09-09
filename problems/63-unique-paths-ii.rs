// Solved 2022-09-09
// Runtime: 0 ms (100.00%)
// Memory Usage: 2.1 MB (92.59%)

impl Solution {
    pub fn unique_paths_with_obstacles(obstacle_grid: Vec<Vec<i32>>) -> i32 {
        if obstacle_grid[0][0] == 1 {
            return 0;
        }

        let mut obstacle_grid = obstacle_grid;
        let m = obstacle_grid.len();
        let n = obstacle_grid[0].len();

        obstacle_grid[0][0] = 1;
        for i in 1..m {
            obstacle_grid[i][0] = if obstacle_grid[i][0] == 0 && obstacle_grid[i - 1][0] == 1 {
                1
            } else {
                0
            }
        }
        for j in 1..n {
            obstacle_grid[0][j] = if obstacle_grid[0][j] == 0 && obstacle_grid[0][j - 1] == 1 {
                1
            } else {
                0
            }
        }
        for i in 1..m {
            for j in 1..n {
                obstacle_grid[i][j] = if obstacle_grid[i][j] == 0 {
                    obstacle_grid[i - 1][j] + obstacle_grid[i][j - 1]
                } else {
                    0
                }
            }
        }

        obstacle_grid[m - 1][n - 1]
    }
}
