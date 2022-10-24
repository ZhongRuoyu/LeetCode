// Solved 2022-10-24
// Runtime: 0 ms (100.00%)
// Memory Usage: 2.1 MB (70.21%)

impl Solution {
    pub fn longest_valid_parentheses(s: String) -> i32 {
        let s = s.chars().collect::<Vec<_>>();
        std::cmp::max(Self::count_from_left(&s), Self::count_from_right(&s))
    }

    fn count_from_left(s: &Vec<char>) -> i32 {
        let mut result = 0;
        let (mut left, mut right) = (0, 0);
        for ch in s.iter() {
            match ch {
                '(' => left += 1,
                ')' => right += 1,
                _ => (),
            }
            match left.cmp(&right) {
                std::cmp::Ordering::Less => {
                    left = 0;
                    right = 0;
                }
                std::cmp::Ordering::Equal => result = std::cmp::max(result, left + right),
                std::cmp::Ordering::Greater => (),
            }
        }
        result
    }

    fn count_from_right(s: &Vec<char>) -> i32 {
        let mut result = 0;
        let (mut left, mut right) = (0, 0);
        for ch in s.iter().rev() {
            match ch {
                '(' => left += 1,
                ')' => right += 1,
                _ => (),
            }
            match left.cmp(&right) {
                std::cmp::Ordering::Less => (),
                std::cmp::Ordering::Equal => result = std::cmp::max(result, left + right),
                std::cmp::Ordering::Greater => {
                    left = 0;
                    right = 0;
                }
            }
        }
        result
    }
}
