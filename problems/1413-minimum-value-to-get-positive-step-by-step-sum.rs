// Solved 2022-11-29
// Runtime: 0 ms (100.00%)
// Memory Usage: 1.9 MB (100.00%)

impl Solution {
    pub fn min_start_value(nums: Vec<i32>) -> i32 {
        let mut sum = 0;
        let mut min_sum = 0;
        for num in nums {
            sum += num;
            min_sum = min_sum.min(sum);
        }
        1 - min_sum
    }
}
