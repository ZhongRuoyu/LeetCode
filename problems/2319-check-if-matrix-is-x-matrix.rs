// Solved 2022-09-06
// Runtime: 5 ms (92.31%)
// Memory Usage: 2.2 MB (92.31%)

impl Solution {
    pub fn check_x_matrix(grid: Vec<Vec<i32>>) -> bool {
        let n = grid.len();
        for (i, row) in grid.iter().enumerate() {
            for (j, element) in row.iter().enumerate() {
                if i == j || i + j == n - 1 {
                    if *element == 0 {
                        return false;
                    }
                } else {
                    if *element != 0 {
                        return false;
                    }
                }
            }
        }
        true
    }
}
