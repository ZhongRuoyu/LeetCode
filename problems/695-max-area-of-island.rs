// Solved 2022-10-27
// Runtime: 4 ms (76.04%)
// Memory Usage: 2.2 MB (94.79%)

impl Solution {
    pub fn max_area_of_island(grid: Vec<Vec<i32>>) -> i32 {
        let mut grid = grid;
        let m = grid.len();
        let n = grid[0].len();
        let mut result = 0;
        for i in 0..m {
            for j in 0..n {
                result = std::cmp::max(result, Self::dfs(&mut grid, i, j));
            }
        }
        result
    }

    fn dfs(grid: &mut Vec<Vec<i32>>, i: usize, j: usize) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        if !(0..m).contains(&i) || !(0..n).contains(&j) || grid[i][j] == 0 {
            return 0;
        }
        grid[i][j] = 0;
        1 + Self::dfs(grid, i + 1, j)
            + Self::dfs(grid, i, j + 1)
            + Self::dfs(grid, i - 1, j)
            + Self::dfs(grid, i, j - 1)
    }
}
