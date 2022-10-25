// Solved 2022-10-25
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (75.00%)

impl Solution {
    pub fn min_subsequence(nums: Vec<i32>) -> Vec<i32> {
        let half_sum = nums.iter().sum::<i32>() / 2;
        let mut priority_queue = nums
            .into_iter()
            .collect::<std::collections::BinaryHeap<_>>();
        let mut result = Vec::new();
        let mut result_sum = 0;
        while result_sum <= half_sum {
            let num = priority_queue.pop().unwrap_or_default();
            result.push(num);
            result_sum += num;
        }
        result
    }
}
