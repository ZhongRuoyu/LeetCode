// Solved 2022-10-10
// Runtime: 13 ms (84.06%)
// Memory Usage: 2.3 MB (85.51%)

impl Solution {
    pub fn array_pair_sum(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        nums.sort_unstable();
        nums.into_iter().step_by(2).sum()
    }
}
