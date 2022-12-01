// Solved 2022-12-01
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (100.00%)

impl Solution {
    pub fn can_make_arithmetic_progression(arr: Vec<i32>) -> bool {
        let mut arr = arr;
        arr.sort_unstable();
        arr.windows(3)
            .all(|window| window[0] - window[1] == window[1] - window[2])
    }
}
