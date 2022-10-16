// Solved 2022-10-16
// Runtime: 2 ms (89.66%)
// Memory Usage: 2 MB (100.00%)

impl Solution {
    pub fn judge_circle(moves: String) -> bool {
        moves.chars().fold((0, 0), |acc, mov| match mov {
            'R' => (acc.0 + 1, acc.1),
            'L' => (acc.0 - 1, acc.1),
            'U' => (acc.0, acc.1 + 1),
            'D' => (acc.0, acc.1 - 1),
            _ => acc,
        }) == (0, 0)
    }
}
