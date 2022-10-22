// Solved 2022-10-22
// Runtime: 8 ms (66.67%)
// Memory Usage: 2.1 MB (100.00%)

impl Solution {
    pub fn reconstruct_queue(people: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut people = people;
        people.sort_unstable_by(|lhs, rhs| match lhs[0].cmp(&rhs[0]) {
            std::cmp::Ordering::Equal => lhs[1].cmp(&rhs[1]),
            _ => lhs[0].cmp(&rhs[0]).reverse(),
        });
        let mut result = Vec::new();
        for person in people {
            result.insert(person[1] as usize, person);
        }
        result
    }
}
