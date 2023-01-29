// Solved 2023-01-29
// Runtime: 0 ms (100.00%)
// Memory Usage: 4.4 MB (68.75%)

impl Solution {
    pub fn num_equiv_domino_pairs(dominoes: Vec<Vec<i32>>) -> i32 {
        let mut count = 0;
        let mut unique = std::collections::HashMap::new();
        dominoes.into_iter().for_each(|domino| {
            unique
                .entry((domino[0].min(domino[1]), domino[0].max(domino[1])))
                .and_modify(|pair_count| {
                    count += *pair_count;
                    *pair_count += 1;
                })
                .or_insert(1);
        });
        count
    }
}
