// Solved 2022-11-23
// Runtime: 3 ms (92.37%)
// Memory Usage: 2.2 MB (51.69%)

impl Solution {
    pub fn find_max_k(nums: Vec<i32>) -> i32 {
        let mut seen = std::collections::HashSet::new();
        let mut max = i32::MIN;
        for num in nums {
            seen.insert(num);
            if seen.contains(&-num) {
                max = max.max(num.abs());
            }
        }
        max.max(-1)
    }
}
