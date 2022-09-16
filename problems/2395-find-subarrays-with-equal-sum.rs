// Solved 2022-09-16
// Runtime: 0 ms (100.00%)
// Memory Usage: 2.1 MB (96.55%)

impl Solution {
    pub fn find_subarrays(nums: Vec<i32>) -> bool {
        let mut sums = std::collections::HashSet::new();
        nums.windows(2)
            .any(|window| !sums.insert(window[0] + window[1]))
    }
}
