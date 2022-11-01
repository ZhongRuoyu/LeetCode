// Solved 2022-11-01
// Runtime: 8 ms (100.00%)
// Memory Usage: 2.6 MB (66.67%)

impl Solution {
    pub fn find_duplicates(nums: Vec<i32>) -> Vec<i32> {
        let mut nums = nums;
        let mut duplicates = Vec::new();
        for i in 0..nums.len() {
            let num = nums[i].abs();
            let reference = &mut nums[num as usize - 1];
            if *reference < 0 {
                duplicates.push(num);
            } else {
                *reference = -*reference;
            }
        }
        duplicates
    }
}
