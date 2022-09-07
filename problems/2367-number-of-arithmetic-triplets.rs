// Solved 2022-09-07
// Runtime: 0 ms (100.00%)
// Memory Usage: 2.1 MB (78.57%)

impl Solution {
    pub fn arithmetic_triplets(nums: Vec<i32>, diff: i32) -> i32 {
        let mut lookup = std::collections::HashSet::new();
        let mut result = 0;
        for num in nums {
            if lookup.contains(&(num - diff)) && lookup.contains(&(num - 2 * diff)) {
                result += 1;
            }
            lookup.insert(num);
        }
        result
    }
}
