// Solved 2022-09-02
// Runtime: 47 ms (91.67%)
// Memory Usage: 3.2 MB (75.00%)

impl Solution {
    pub fn min_pair_sum(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        nums.sort_unstable();
        let (low, high) = nums.split_at(nums.len() / 2);
        low.iter()
            .zip(high.iter().rev())
            .map(|(l, h)| l + h)
            .max()
            .unwrap_or_default()
    }
}
