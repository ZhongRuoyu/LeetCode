// Solved 2022-10-04
// Runtime: 0 ms (100.00%)
// Memory Usage: 2.1 MB (77.78%)

impl Solution {
    pub fn odd_cells(m: i32, n: i32, indices: Vec<Vec<i32>>) -> i32 {
        let mut odd_rows = vec![false; m as usize];
        let mut odd_cols = vec![false; n as usize];
        let mut row_count = 0;
        let mut col_count = 0;
        for index in indices {
            let row = &mut odd_rows[index[0] as usize];
            let col = &mut odd_cols[index[1] as usize];
            *row = !*row;
            *col = !*col;
            row_count += if *row { 1 } else { -1 };
            col_count += if *col { 1 } else { -1 };
        }
        (m - row_count) * col_count + (n - col_count) * row_count
    }
}
