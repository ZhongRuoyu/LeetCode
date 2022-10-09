// Solved 2022-10-09
// Runtime: 85 ms (100.00%)
// Memory Usage: 3.7 MB (50.00%)

impl Solution {
    pub fn get_maximum_xor(nums: Vec<i32>, maximum_bit: i32) -> Vec<i32> {
        nums.iter()
            .enumerate()
            .fold::<(_, _), _>(
                ((1 << maximum_bit) - 1, vec![0; nums.len()]),
                |(mut curr, mut result), (i, num)| {
                    curr ^= *num;
                    result[nums.len() - i - 1] = curr;
                    (curr, result)
                },
            )
            .1
    }
}
