// Solved 2022-11-19
// Runtime: 0 ms (100.00%)
// Memory Usage: 2.2 MB (100.00%)

impl Solution {
    pub fn partition_string(s: String) -> i32 {
        let mut chars = 0;
        let mut count = 1;
        for ch in s.chars() {
            if chars & (1 << (ch as u8 - 'a' as u8)) != 0 {
                count += 1;
                chars = 0;
            }
            chars |= 1 << (ch as u8 - 'a' as u8);
        }
        count
    }
}
