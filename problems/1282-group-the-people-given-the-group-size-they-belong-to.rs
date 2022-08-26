// Solved 2022-08-26
// Runtime: 4 ms (90.00%)
// Memory Usage: 2.2 MB (100.00%)

impl Solution {
    pub fn group_the_people(group_sizes: Vec<i32>) -> Vec<Vec<i32>> {
        let mut result = Vec::new();
        let mut groups = std::collections::HashMap::new();
        for (person, group_size) in group_sizes.iter().enumerate() {
            let group = groups.entry(group_size).or_insert(vec![]);
            group.push(person as i32);
            if group.len() as i32 == *group_size {
                result.push(groups.remove_entry(group_size).unwrap().1);
            }
        }
        result
    }
}
