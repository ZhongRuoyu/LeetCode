// Solved 2022-12-11
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (100.00%)

impl Solution {
    pub fn number_of_arithmetic_slices(nums: Vec<i32>) -> i32 {
        nums.windows(3)
            .fold((0, 0), |(mut acc, mut result), window| {
                if window[0] - window[1] == window[1] - window[2] {
                    acc += 1;
                    result += acc;
                } else {
                    acc = 0;
                }
                (acc, result)
            })
            .1
    }
}
