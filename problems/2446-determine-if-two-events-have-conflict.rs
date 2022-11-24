// Solved 2022-11-24
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (98.28%)

impl Solution {
    pub fn have_conflict(event1: Vec<String>, event2: Vec<String>) -> bool {
        event1[0] <= event2[1] && event2[0] <= event1[1]
    }
}
