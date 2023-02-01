// Solved 2023-02-01
// Runtime: 0 ms (100.00%)
// Memory Usage: 1.9 MB (93.67%)

impl Solution {
    pub fn alternate_digit_sum(n: i32) -> i32 {
        let mut n = n;
        let mut digit_count = 0;
        let mut digit_sum = 0;
        while n > 0 {
            digit_count += 1;
            if digit_count % 2 == 0 {
                digit_sum -= n % 10;
            } else {
                digit_sum += n % 10;
            }
            n /= 10;
        }
        if digit_count % 2 == 0 {
            -digit_sum
        } else {
            digit_sum
        }
    }
}
