// Solved 2022-10-13
// Runtime: 0 ms (100.00%)
// Memory Usage: 2.2 MB (73.08%)

impl Solution {
    pub fn sort_array_by_parity(nums: Vec<i32>) -> Vec<i32> {
        let mut nums = nums;
        let mut lhs = 0usize;
        let mut rhs = nums.len() - 1;
        while lhs < rhs {
            if (nums[lhs] % 2).abs() > (nums[rhs] % 2).abs() {
                let temp = nums[lhs];
                nums[lhs] = nums[rhs];
                nums[rhs] = temp;
            }
            if nums[lhs] % 2 == 0 {
                lhs += 1;
            }
            if nums[rhs] % 2 != 0 {
                rhs -= 1;
            }
        }
        nums
    }
}
