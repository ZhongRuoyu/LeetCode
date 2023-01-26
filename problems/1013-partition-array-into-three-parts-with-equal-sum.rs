// Solved 2023-01-26
// Runtime: 0 ms (100.00%)
// Memory Usage: 2.8 MB (60.00%)

impl Solution {
    pub fn can_three_parts_equal_sum(arr: Vec<i32>) -> bool {
        let sum = arr.iter().sum::<i32>();
        if sum % 3 != 0 {
            return false;
        }
        let target_sum = sum / 3;
        let mut parts_count = 0;
        let mut curr_sum = 0;
        for num in arr {
            curr_sum += num;
            if target_sum * (parts_count + 1) == curr_sum {
                parts_count += 1;
            }
        }
        parts_count >= 3
    }
}
