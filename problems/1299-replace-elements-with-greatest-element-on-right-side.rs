// Solved 2022-08-27
// Runtime: 3 ms (96.15%)
// Memory Usage: 2.2 MB (94.23%)

impl Solution {
    pub fn replace_elements(arr: Vec<i32>) -> Vec<i32> {
        let mut result = vec![0; arr.len()];
        let mut max = -1;
        for (i, num) in arr.iter().enumerate().rev() {
            result[i] = max;
            max = std::cmp::max(max, *num);
        }
        result
    }
}
