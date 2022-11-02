// Solved 2022-11-02
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (100.00%)

impl Solution {
    pub fn shortest_to_char(s: String, c: char) -> Vec<i32> {
        let s = s.chars().collect::<Vec<_>>();
        let mut result = vec![i32::MAX; s.len()];

        let mut prev = None;
        for i in 0..s.len() {
            if s[i] == c {
                prev = Some(i);
            }
            match prev {
                Some(index) => result[i] = (i - index) as i32,
                None => (),
            }
        }

        let mut prev = None;
        for i in (0..s.len()).rev() {
            if s[i] == c {
                prev = Some(i);
            }
            match prev {
                Some(index) => result[i] = std::cmp::min(result[i], (index - i) as i32),
                None => (),
            }
        }

        result
    }
}
