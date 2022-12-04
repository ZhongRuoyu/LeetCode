// Solved 2022-12-04
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (66.67%)

impl Solution {
    pub fn sort_even_odd(nums: Vec<i32>) -> Vec<i32> {
        let mut even = nums.iter().skip(0).step_by(2).collect::<Vec<_>>();
        let mut odd = nums.iter().skip(1).step_by(2).collect::<Vec<_>>();
        even.sort_unstable_by_key(|&&x| x);
        odd.sort_unstable_by_key(|&&x| -x);
        (0..nums.len())
            .map(|i| match i % 2 {
                0 => even[i / 2].to_owned(),
                1 => odd[i / 2].to_owned(),
                _ => unreachable!(),
            })
            .collect()
    }
}
