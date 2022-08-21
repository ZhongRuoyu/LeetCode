// Solved 2022-08-21
// Runtime: 0 ms (100.00%)
// Memory Usage: 2.1 MB (93.75%)

impl Solution {
    pub fn cal_points(ops: Vec<String>) -> i32 {
        let mut points: Vec<i32> = Vec::new();
        for op in ops {
            if op == "+" {
                points.push(points[points.len() - 1] + points[points.len() - 2]);
            } else if op == "D" {
                points.push(points[points.len() - 1] * 2);
            } else if op == "C" {
                points.pop();
            } else {
                points.push(op.parse::<i32>().unwrap_or_default());
            }
        }
        points.iter().sum()
    }
}
