// Solved 2022-11-03
// Runtime: 17 ms (100.00%)
// Memory Usage: 2.4 MB (100.00%)

impl Solution {
    pub fn spiral_matrix_iii(rows: i32, cols: i32, r_start: i32, c_start: i32) -> Vec<Vec<i32>> {
        let mut result = vec![vec![r_start, c_start]];
        let (mut row, mut col) = (r_start, c_start);
        for off_by in (1..(2 * std::cmp::max(rows, cols))).step_by(2) {
            for direction in 0..4 {
                for _ in 0..(off_by + direction / 2) {
                    row += [0, 1, 0, -1][direction as usize];
                    col += [1, 0, -1, 0][direction as usize];
                    if (0..rows).contains(&row) && (0..cols).contains(&col) {
                        result.push(vec![row, col]);
                        if result.len() == (rows * cols) as usize {
                            return result;
                        }
                    }
                }
            }
        }
        result
    }
}
