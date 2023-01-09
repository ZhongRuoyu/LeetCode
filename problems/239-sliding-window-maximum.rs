// Solved 2023-01-09
// Runtime: 60 ms (100.00%)
// Memory Usage: 3.4 MB (98.28%)

impl Solution {
    pub fn max_sliding_window(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let mut decreasing_window = std::collections::VecDeque::new();
        let mut result = Vec::new();
        for i in 0..nums.len() {
            while let Some(&back_index) = decreasing_window.back() {
                if nums[i] < nums[back_index as usize] {
                    break;
                }
                decreasing_window.pop_back();
            }
            decreasing_window.push_back(i as i32);
            if i as i32 >= k - 1 {
                while let Some(&front_index) = decreasing_window.front() {
                    if front_index > i as i32 - k {
                        break;
                    }
                    decreasing_window.pop_front();
                }
                result.push(nums[*decreasing_window.front().unwrap_or(&0) as usize]);
            }
        }
        result
    }
}

// Finally back to school. All the best!
