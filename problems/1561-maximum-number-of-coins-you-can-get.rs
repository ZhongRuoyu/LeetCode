// Solved 2022-09-21
// Runtime: 23 ms (100.00%)
// Memory Usage: 3.2 MB (87.50%)

impl Solution {
    pub fn max_coins(piles: Vec<i32>) -> i32 {
        let mut piles = piles;
        piles.sort_unstable();
        ((piles.len() / 3)..piles.len())
            .step_by(2)
            .map(|i| piles[i])
            .sum()
    }
}
