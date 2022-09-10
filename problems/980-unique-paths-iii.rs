// Solved 2022-09-10
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (100.00%)

impl Solution {
    pub fn unique_paths_iii(grid: Vec<Vec<i32>>) -> i32 {
        let mut grid = grid;
        let mut empty = 1;
        let (mut start_i, mut start_j) = (0, 0);
        for (i, row) in grid.iter().enumerate() {
            for (j, square) in row.iter().enumerate() {
                match square {
                    1 => {
                        start_i = i;
                        start_j = j;
                    }
                    0 => empty += 1,
                    _ => (),
                }
            }
        }
        Self::dfs(&mut grid, start_i, start_j, empty)
    }

    fn dfs(grid: &mut Vec<Vec<i32>>, i: usize, j: usize, current_empty: i32) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        if !(0..m).contains(&i) || !(0..n).contains(&j) || grid[i][j] < 0 {
            0
        } else if grid[i][j] == 2 {
            if current_empty == 0 {
                1
            } else {
                0
            }
        } else {
            grid[i][j] = -2;
            let mut result = 0;
            result += Self::dfs(grid, i + 1, j, current_empty - 1);
            result += Self::dfs(grid, i - 1, j, current_empty - 1);
            result += Self::dfs(grid, i, j + 1, current_empty - 1);
            result += Self::dfs(grid, i, j - 1, current_empty - 1);
            grid[i][j] = 0;
            result
        }
    }
}
