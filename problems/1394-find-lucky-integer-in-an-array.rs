// Solved 2022-12-15
// Runtime: 0 ms (100.00%)
// Memory Usage: 2.1 MB (100.00%)

impl Solution {
    pub fn find_lucky(arr: Vec<i32>) -> i32 {
        arr.into_iter()
            .fold(std::collections::BTreeMap::new(), |mut freqs, num| {
                freqs.entry(-num).and_modify(|freq| *freq += 1).or_insert(1);
                freqs
            })
            .into_iter()
            .find_map(|(neg, freq)| if -neg == freq { Some(-neg) } else { None })
            .unwrap_or(-1)
    }
}
