// Solved 2022-11-08
// Runtime: 0 ms (100.00%)
// Memory Usage: 2.1 MB (100.00%)

impl Solution {
    pub fn can_be_equal(target: Vec<i32>, arr: Vec<i32>) -> bool {
        let mut numbers = std::collections::HashMap::new();
        target.iter().for_each(|num| {
            numbers.entry(num).and_modify(|x| *x += 1).or_insert(1);
        });
        arr.iter().for_each(|num| {
            numbers.entry(num).and_modify(|x| *x -= 1).or_insert(-1);
        });
        numbers.values().all(|x| *x == 0)
    }
}
