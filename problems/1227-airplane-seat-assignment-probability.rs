// Solved 2022-08-25
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (100.00%)

impl Solution {
    pub fn nth_person_gets_nth_seat(n: i32) -> f64 {
        if n >= 2 {
            0.5
        } else {
            1.0
        }
    }
}
