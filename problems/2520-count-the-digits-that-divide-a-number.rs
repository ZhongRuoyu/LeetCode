// Solved 2023-01-19
// Runtime: 1 ms (80.00%)
// Memory Usage: 1.9 MB (97.65%)

impl Solution {
    pub fn count_digits(num: i32) -> i32 {
        let mut count = 0;
        let mut x = num;
        while x > 0 {
            if x % 10 != 0 && num % (x % 10) == 0 {
                count += 1;
            }
            x /= 10;
        }
        count
    }
}
