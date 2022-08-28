// Solved 2022-08-28
// Runtime: 3 ms (71.43%)
// Memory Usage: 2 MB (71.43%)

impl Solution {
    pub fn sort_by_bits(arr: Vec<i32>) -> Vec<i32> {
        let mut result = arr;
        result.sort_unstable_by(|x, y| {
            let x_ones = x.count_ones();
            let y_ones = y.count_ones();
            if x_ones == y_ones {
                x.cmp(&y)
            } else {
                x_ones.cmp(&y_ones)
            }
        });
        result
    }
}
