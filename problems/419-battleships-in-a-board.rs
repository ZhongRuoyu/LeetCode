// Solved 2022-10-23
// Runtime: 0 ms (100.00%)
// Memory Usage: 3.9 MB (75.00%)

impl Solution {
    pub fn count_battleships(board: Vec<Vec<char>>) -> i32 {
        let m = board.len();
        let n = board[0].len();
        let mut count = 0;
        for i in 0..m {
            for j in 0..n {
                if board[i][j] != 'X'
                    || i > 0 && board[i - 1][j] == 'X'
                    || j > 0 && board[i][j - 1] == 'X'
                {
                    continue;
                }
                count += 1;
            }
        }
        count
    }
}
