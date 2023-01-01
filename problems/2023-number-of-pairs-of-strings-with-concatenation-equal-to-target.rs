// Solved 2023-01-01
// Runtime: 2 ms (85.71%)
// Memory Usage: 2.1 MB (85.71%)

impl Solution {
    pub fn num_of_pairs(nums: Vec<String>, target: String) -> i32 {
        let freq = nums
            .into_iter()
            .fold(std::collections::HashMap::new(), |mut acc, num| {
                acc.entry(num).and_modify(|count| *count += 1).or_insert(1);
                acc
            });
        let mut result = 0;
        for (prefix, prefix_count) in freq.iter() {
            if target.starts_with(prefix) {
                if prefix.repeat(2) == target {
                    result += prefix_count * (prefix_count - 1);
                } else {
                    let suffix = target
                        .chars()
                        .skip(prefix.chars().count())
                        .collect::<String>();
                    match freq.get(&suffix) {
                        Some(suffix_count) => {
                            result += prefix_count * suffix_count;
                        }
                        None => (),
                    }
                }
            }
        }
        result
    }
}

// Happy new year :D
