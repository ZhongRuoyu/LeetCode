// Solved 2023-01-27
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (100.00%)

impl Solution {
    pub fn last_stone_weight(stones: Vec<i32>) -> i32 {
        let mut stones = stones
            .iter()
            .map(|x| *x)
            .collect::<std::collections::BinaryHeap<_>>();
        while stones.len() > 1 {
            let y = stones.pop().unwrap_or_default();
            let x = stones.pop().unwrap_or_default();
            if x != y {
                stones.push(y - x);
            }
        }
        stones.pop().unwrap_or_default()
    }
}
