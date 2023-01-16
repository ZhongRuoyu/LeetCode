// Solved 2023-01-16
// Runtime: 36 ms (95.65%)
// Memory Usage: 3.7 MB (100.00%)

impl Solution {
    pub fn count_distinct_integers(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        let n = nums.len();
        nums.reserve(n);
        for i in 0..n {
            let mut num = nums[i];
            let mut rev = 0;
            while num > 0 {
                rev = rev * 10 + num % 10;
                num /= 10;
            }
            nums.push(rev);
        }
        nums.sort_unstable();
        nums.dedup();
        nums.len() as i32
    }
}
