// Solved 2022-12-16
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (100.00%)

impl Solution {
    pub fn mirror_reflection(p: i32, q: i32) -> i32 {
        let lcm = Self::lcm(p, q);
        if lcm / q % 2 == 0 {
            2
        } else if lcm / p % 2 == 0 {
            0
        } else {
            1
        }
    }

    fn lcm(x: i32, y: i32) -> i32 {
        if x == 0 || y == 0 {
            return 0;
        }
        x / Self::gcd(x, y) * y
    }

    fn gcd(x: i32, y: i32) -> i32 {
        if y == 0 {
            x
        } else {
            Self::gcd(y, x % y)
        }
    }
}
