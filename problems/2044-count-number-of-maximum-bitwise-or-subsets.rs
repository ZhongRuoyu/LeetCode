// Solved 2022-11-12
// Runtime: 13 ms (100.00%)
// Memory Usage: 2 MB (100.00%)

impl Solution {
    pub fn count_max_or_subsets(nums: Vec<i32>) -> i32 {
        let max_or = nums.iter().fold(0, |acc, num| acc | num);
        Self::dfs(max_or, &nums, 0, 0)
    }

    fn dfs(max_or: i32, nums: &Vec<i32>, current_or: i32, current_index: usize) -> i32 {
        if current_index == nums.len() {
            return if current_or == max_or { 1 } else { 0 };
        }
        Self::dfs(
            max_or,
            nums,
            current_or | nums[current_index],
            current_index + 1,
        ) + Self::dfs(max_or, nums, current_or, current_index + 1)
    }
}
