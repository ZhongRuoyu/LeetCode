// Solved 2022-11-27
// Runtime: 13 ms (100.00%)
// Memory Usage: 3.2 MB (95.24%)

impl Solution {
    pub fn minimum_abs_difference(arr: Vec<i32>) -> Vec<Vec<i32>> {
        let mut arr = arr;
        arr.sort_unstable();
        let min_abs_diff = arr
            .windows(2)
            .map(|window| window[1] - window[0])
            .min()
            .unwrap_or_default();
        arr.windows(2)
            .filter(|window| window[1] - window[0] == min_abs_diff)
            .map(|window| window.to_owned())
            .collect()
    }
}
