// Solved 2022-09-23
// Runtime: 72 ms (100.00%)
// Memory Usage: 4.9 MB (62.50%)

impl Solution {
    pub fn finding_users_active_minutes(logs: Vec<Vec<i32>>, k: i32) -> Vec<i32> {
        let mut lookup = std::collections::HashMap::new();
        for log in logs {
            lookup
                .entry(log[0])
                .or_insert_with(|| std::collections::HashSet::new())
                .insert(log[1]);
        }

        let mut result = vec![0; k as usize];
        lookup.iter().for_each(|user| {
            result[user.1.len() - 1] += 1;
        });

        result
    }
}
