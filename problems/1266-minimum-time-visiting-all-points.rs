// Solved 2022-09-27
// Runtime: 0 ms (100.00%)
// Memory Usage: 2.1 MB (91.67%)

impl Solution {
    pub fn min_time_to_visit_all_points(points: Vec<Vec<i32>>) -> i32 {
        points
            .windows(2)
            .into_iter()
            .map(|pts| std::cmp::max((pts[0][0] - pts[1][0]).abs(), (pts[0][1] - pts[1][1]).abs()))
            .sum()
    }
}
