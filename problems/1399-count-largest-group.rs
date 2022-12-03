// Solved 2022-12-03
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (100.00%)

impl Solution {
    pub fn count_largest_group(n: i32) -> i32 {
        let mut groups = std::collections::HashMap::new();
        let mut largest_group_size = 0;
        (1..=n)
            .map(|mut x| {
                let mut result = 0;
                while x > 0 {
                    result += x % 10;
                    x /= 10;
                }
                result
            })
            .for_each(|sum| {
                let sum_count = groups.entry(sum).or_insert(0);
                *sum_count += 1;
                largest_group_size = largest_group_size.max(*sum_count);
            });
        groups
            .into_iter()
            .map(|(_sum, count)| count)
            .filter(|&count| count == largest_group_size)
            .count() as i32
    }
}
