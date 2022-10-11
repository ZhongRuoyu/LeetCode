// Solved 2022-10-11
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (64.29%)

impl Solution {
    pub fn min_add_to_make_valid(s: String) -> i32 {
        let mut balance = 0;
        let mut compensation = 0;
        for ch in s.chars() {
            balance += if ch == '(' { 1 } else { -1 };
            if balance < 0 {
                compensation += -balance;
                balance = 0;
            }
        }
        balance + compensation
    }
}
