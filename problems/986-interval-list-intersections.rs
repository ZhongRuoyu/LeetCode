// Solved 2022-11-04
// Runtime: 6 ms (94.44%)
// Memory Usage: 2.3 MB (86.11%)

impl Solution {
    pub fn interval_intersection(
        first_list: Vec<Vec<i32>>,
        second_list: Vec<Vec<i32>>,
    ) -> Vec<Vec<i32>> {
        let mut first = 0;
        let mut second = 0;
        let mut result = Vec::new();
        while first < first_list.len() && second < second_list.len() {
            let lo = std::cmp::max(first_list[first][0], second_list[second][0]);
            let hi = std::cmp::min(first_list[first][1], second_list[second][1]);
            if lo <= hi {
                result.push(vec![lo, hi]);
            }
            if first_list[first][1] < second_list[second][1] {
                first += 1;
            } else {
                second += 1;
            }
        }
        result
    }
}
