// Solved 2023-01-15
// Runtime: 1 ms (100.00%)
// Memory Usage: 2.1 MB (75.00%)

impl Solution {
    pub fn max_satisfaction(satisfaction: Vec<i32>) -> i32 {
        let mut satisfaction = satisfaction;
        satisfaction.sort_unstable_by_key(|dish| std::cmp::Reverse(*dish));
        let mut total_satisfaction = 0;
        let mut result = 0;
        for dish in satisfaction {
            if total_satisfaction + dish < 0 {
                break;
            }
            total_satisfaction += dish;
            result += total_satisfaction;
        }
        result
    }
}
