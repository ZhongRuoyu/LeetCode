// Solved 2023-01-24
// Runtime: 7 ms (96.77%)
// Memory Usage: 2.4 MB (87.10%)

impl Solution {
    pub fn fair_candy_swap(alice_sizes: Vec<i32>, bob_sizes: Vec<i32>) -> Vec<i32> {
        let alice_sum = alice_sizes.iter().sum::<i32>();
        let bob_sum = bob_sizes.iter().sum::<i32>();
        let bob_sizes = bob_sizes
            .into_iter()
            .collect::<std::collections::HashSet<_>>();
        let diff = (bob_sum - alice_sum) / 2;
        for size in alice_sizes {
            if bob_sizes.contains(&(size + diff)) {
                return vec![size, size + diff];
            }
        }
        vec![]
    }
}
