// Solved 2022-11-15
// Runtime: 32 ms (100.00%)
// Memory Usage: 3.5 MB (100.00%)

impl Solution {
    pub fn partition_array(nums: Vec<i32>, k: i32) -> i32 {
        let mut nums = nums;
        nums.sort_unstable();
        let mut max = i32::MIN;
        let mut min = i32::MAX;
        let mut result = 1;
        for num in nums {
            max = std::cmp::max(max, num);
            min = std::cmp::min(min, num);
            if max - min > k {
                result += 1;
                max = num;
                min = num;
            }
        }
        result
    }
}
