// Solved 2022-08-24
// Runtime: 0 ms (100.00%)
// Memory Usage: 2.1 MB (100.00%)

impl Solution {
    pub fn num_moves_stones(a: i32, b: i32, c: i32) -> Vec<i32> {
        let mut stones = vec![a, b, c];
        stones.sort_unstable();
        if stones[2] - stones[0] == 2 {
            vec![0, 0]
        } else {
            vec![
                if std::cmp::min(stones[1] - stones[0], stones[2] - stones[1]) <= 2 {
                    1
                } else {
                    2
                },
                stones[2] - stones[0] - 2,
            ]
        }
    }
}
