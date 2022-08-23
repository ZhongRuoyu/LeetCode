// Solved 2022-08-23
// Runtime: 46 ms (100.00%)
// Memory Usage: 7.4 MB (100.00%)

struct Solution {
    indices: std::collections::HashMap<i32, std::collections::VecDeque<i32>>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Solution {
    fn new(nums: Vec<i32>) -> Self {
        let mut indices = std::collections::HashMap::new();
        for (i, num) in nums.iter().enumerate() {
            indices
                .entry(*num)
                .or_insert(std::collections::VecDeque::new())
                .push_back(i as i32);
        }
        Self { indices }
    }

    fn pick(&mut self, target: i32) -> i32 {
        *self
            .indices
            .entry(target)
            .and_modify(|indices| indices.rotate_left(1))
            .or_default()
            .front()
            .unwrap_or(&0)
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * let obj = Solution::new(nums);
 * let ret_1: i32 = obj.pick(target);
 */
