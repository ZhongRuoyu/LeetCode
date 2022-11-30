// Solved 2022-11-30
// Runtime: 18 ms (83.33%)
// Memory Usage: 2.7 MB (96.67%)

impl Solution {
    pub fn sum_even_after_queries(nums: Vec<i32>, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let mut nums = nums;
        let mut sum = nums.iter().filter(|&&num| num % 2 == 0).sum();
        let mut result = Vec::with_capacity(nums.len());
        for query in queries {
            let num = &mut nums[query[1] as usize];
            if *num % 2 == 0 {
                sum -= *num;
            }
            *num += query[0];
            if *num % 2 == 0 {
                sum += *num;
            }
            result.push(sum);
        }
        result
    }
}
