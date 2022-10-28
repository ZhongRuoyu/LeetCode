// Solved 2022-10-28
// Runtime: 13 ms (90.91%)
// Memory Usage: 2.4 MB (90.91%)

impl Solution {
    pub fn num_enclaves(grid: Vec<Vec<i32>>) -> i32 {
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

        grid.into_iter()
            .map(|row| row.into_iter().sum::<i32>())
            .sum()
    }

    fn flood_fill(grid: &mut Vec<Vec<i32>>, i: usize, j: usize) {
        let m = grid.len();
        let n = grid[0].len();
        let mut queue = std::collections::VecDeque::new();
        queue.push_back((i, j));
        while let Some((i, j)) = queue.pop_front() {
            if grid[i][j] == 0 {
                continue;
            }
            grid[i][j] = 0;
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
