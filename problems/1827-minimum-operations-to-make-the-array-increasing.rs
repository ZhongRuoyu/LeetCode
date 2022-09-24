// Solved 2022-09-24
// Runtime: 0 ms (100.00%)
// Memory Usage: 2.1 MB (93.75%)

impl Solution {
    pub fn min_operations(nums: Vec<i32>) -> i32 {
        let mut result = 0;
        let mut last = 0;
        for num in nums {
            result += std::cmp::max(0, last - num + 1);
            last = std::cmp::max(num, last + 1);
        }
        result
    }
}
