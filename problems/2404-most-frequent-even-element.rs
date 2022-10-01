// Solved 2022-10-01
// Runtime: 6 ms (100.00%)
// Memory Usage: 2.2 MB (81.32%)

impl Solution {
    pub fn most_frequent_even(nums: Vec<i32>) -> i32 {
        let mut lookup = std::collections::HashMap::new();
        let mut min = i32::MAX;
        let mut min_count = 0;
        for num in nums {
            if num % 2 != 0 {
                continue;
            }
            let count = lookup.entry(num).and_modify(|x| *x += 1).or_insert(1);
            if *count > min_count || *count == min_count && num < min {
                min = num;
                min_count = *count;
            }
        }
        if min_count == 0 {
            -1
        } else {
            min
        }
    }
}
