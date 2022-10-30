// Solved 2022-10-30
// Runtime: 50 ms (100.00%)
// Memory Usage: 4.3 MB (90.00%)

impl Solution {
    pub fn count_sub_islands(grid1: Vec<Vec<i32>>, grid2: Vec<Vec<i32>>) -> i32 {
        let m = grid1.len();
        let n = grid1[0].len();
        let mut grid2 = grid2;
        let mut result = 0;
        for i in 0..m {
            for j in 0..n {
                if grid2[i][j] != 0 && Self::flood_fill(&grid1, &mut grid2, i, j) {
                    result += 1;
                }
            }
        }
        result
    }

    fn flood_fill(grid1: &Vec<Vec<i32>>, grid2: &mut Vec<Vec<i32>>, i: usize, j: usize) -> bool {
        if grid2[i][j] == 0 {
            return false;
        }
        let m = grid1.len();
        let n = grid1[0].len();

        let mut is_sub_island = true;
        let mut queue = std::collections::VecDeque::new();
        queue.push_back((i, j));
        while let Some((i, j)) = queue.pop_front() {
            if grid2[i][j] == 0 {
                continue;
            }
            grid2[i][j] = 0;
            if grid1[i][j] == 0 {
                is_sub_island = false;
            }
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
        is_sub_island
    }
}
