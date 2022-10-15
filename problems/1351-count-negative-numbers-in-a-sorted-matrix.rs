// Solved 2022-10-15
// Runtime: 0 ms (100.00%)
// Memory Usage: 2.2 MB (75.00%)

impl Solution {
    pub fn count_negatives(grid: Vec<Vec<i32>>) -> i32 {
        let (m, n) = (grid.len(), grid[0].len());
        let (mut i, mut j) = (0, n - 1);
        let mut count = 0;
        while i < m {
            while j != usize::MAX && grid[i][j] < 0 {
                j -= 1;
            }
            count += n - 1 - j;
            i += 1;
        }
        count as i32
    }
}
