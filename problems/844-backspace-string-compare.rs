// Solved 2022-11-21
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (91.13%)

impl Solution {
    pub fn backspace_compare(s: String, t: String) -> bool {
        let s = s.chars().collect::<Vec<_>>();
        let t = t.chars().collect::<Vec<_>>();
        let mut s_index = s.len() as isize - 1;
        let mut t_index = t.len() as isize - 1;
        let mut s_skip = 0;
        let mut t_skip = 0;
        while s_index >= 0 || t_index >= 0 {
            while s_index >= 0 {
                if s[s_index as usize] == '#' {
                    s_skip += 1;
                    s_index -= 1;
                } else if s_skip > 0 {
                    s_skip -= 1;
                    s_index -= 1;
                } else {
                    break;
                }
            }
            while t_index >= 0 {
                if t[t_index as usize] == '#' {
                    t_skip += 1;
                    t_index -= 1;
                } else if t_skip > 0 {
                    t_skip -= 1;
                    t_index -= 1;
                } else {
                    break;
                }
            }
            if s_index >= 0 && t_index >= 0 {
                if s[s_index as usize] != t[t_index as usize] {
                    return false;
                }
            } else if (s_index >= 0) ^ (t_index >= 0) {
                return false;
            }
            s_index -= 1;
            t_index -= 1;
        }
        true
    }
}
