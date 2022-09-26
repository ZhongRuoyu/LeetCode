// Solved 2022-09-26
// Runtime: 12 ms (87.50%)
// Memory Usage: 3.3 MB (100.00%)

impl Solution {
    pub fn maximum_xor(nums: Vec<i32>) -> i32 {
        nums.into_iter()
            .reduce(|sum, num| sum | num)
            .unwrap_or_default()
    }
}
