// Solved 2022-08-30
// Runtime: 2 ms (100.00%)
// Memory Usage: 2 MB (90.00%)

impl Solution {
    pub fn min_operations(boxes: String) -> Vec<i32> {
        let boxes: Vec<_> = boxes.chars().map(|ch| ch != '0').collect();
        let mut result = vec![0; boxes.len()];

        let mut ball_count = 0;
        let mut operation_count = 0;
        for (i, ch) in boxes.iter().enumerate() {
            result[i] += operation_count;
            if *ch {
                ball_count += 1;
            }
            operation_count += ball_count;
        }

        let mut ball_count = 0;
        let mut operation_count = 0;
        for (i, ch) in boxes.iter().enumerate().rev() {
            result[i] += operation_count;
            if *ch {
                ball_count += 1;
            }
            operation_count += ball_count;
        }

        result
    }
}
