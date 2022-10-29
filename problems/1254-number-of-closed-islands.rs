// Solved 2022-10-29
// Runtime: 3 ms (76.00%)
// Memory Usage: 2.2 MB (84.00%)

impl Solution {
    pub fn closed_island(grid: Vec<Vec<i32>>) -> i32 {
        let mut grid = grid;
        let m = grid.len();
        let n = grid[0].len();

        for i in 0..m {
            Self::flood_fill(&mut grid, i, 0);
            Self::flood_fill(&mut grid, i, n - 1);
        }
        for j in 0..n {
            Self::flood_fill(&mut grid, 0, j);
            Self::flood_fill(&mut grid, m - 1, j);
        }

        let mut result = 0;
        for i in 0..m {
            for j in 0..n {
                if grid[i][j] == 0 {
                    Self::flood_fill(&mut grid, i, j);
                    result += 1;
                }
            }
        }

        result
    }

    fn flood_fill(grid: &mut Vec<Vec<i32>>, i: usize, j: usize) {
        if grid[i][j] != 0 {
            return;
        }
        let m = grid.len();
        let n = grid[0].len();

        let mut queue = std::collections::VecDeque::new();
        queue.push_back((i, j));
        while let Some((i, j)) = queue.pop_front() {
            if grid[i][j] != 0 {
                continue;
            }
            grid[i][j] = 1;
            if i > 0 {
                queue.push_back((i - 1, j));
            }
            if i + 1 < m {
                queue.push_back((i + 1, j));
            }
            if j > 0 {
                queue.push_back((i, j - 1));
            }
            if j + 1 < n {
                queue.push_back((i, j + 1));
            }
        }
    }
}
