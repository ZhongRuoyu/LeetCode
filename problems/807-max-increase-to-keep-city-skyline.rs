// Solved 2022-09-12
// Runtime: 0 ms (100.00%)
// Memory Usage: 2.1 MB (63.64%)

impl Solution {
    pub fn max_increase_keeping_skyline(grid: Vec<Vec<i32>>) -> i32 {
        let mut row_maxes = vec![0; grid.len()];
        let mut col_maxes = vec![0; grid.len()];
        for (i, row) in grid.iter().enumerate() {
            for (j, cell) in row.iter().enumerate() {
                if *cell > row_maxes[i] {
                    row_maxes[i] = *cell;
                }
                if *cell > col_maxes[j] {
                    col_maxes[j] = *cell;
                }
            }
        }

        let mut result = 0;
        for (i, row) in grid.iter().enumerate() {
            for (j, cell) in row.iter().enumerate() {
                result += std::cmp::min(row_maxes[i], col_maxes[j]) - cell;
            }
        }

        result
    }
}
