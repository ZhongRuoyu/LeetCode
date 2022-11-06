// Solved 2022-11-06
// Runtime: 1 ms (100.00%)
// Memory Usage: 2.1 MB (100.00%)

impl Solution {
    pub fn queens_attackthe_king(queens: Vec<Vec<i32>>, king: Vec<i32>) -> Vec<Vec<i32>> {
        let queens = {
            let mut arr = vec![vec![false; 8]; 8];
            for queen in queens {
                arr[queen[0] as usize][queen[1] as usize] = true;
            }
            arr
        };
        let king = (king[0], king[1]);

        let mut result = Vec::new();
        for direction in [
            (1, 0),
            (1, 1),
            (0, 1),
            (-1, 1),
            (-1, 0),
            (-1, -1),
            (0, -1),
            (1, -1),
        ] {
            for distance in 1..8 {
                let position = (
                    king.0 + direction.0 * distance,
                    king.1 + direction.1 * distance,
                );
                if !(0..8).contains(&position.0) || !(0..8).contains(&position.1) {
                    break;
                }
                if queens[position.0 as usize][position.1 as usize] {
                    result.push(vec![position.0, position.1]);
                    break;
                }
            }
        }
        result
    }
}
