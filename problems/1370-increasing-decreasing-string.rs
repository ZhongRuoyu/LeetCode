// Solved 2022-10-05
// Runtime: 0 ms (100.00%)
// Memory Usage: 2.2 MB (57.14%)

impl Solution {
    pub fn sort_string(s: String) -> String {
        let mut lookup = s
            .chars()
            .fold(std::collections::HashMap::new(), |mut map, ch| {
                *map.entry(ch as u32 - 'a' as u32).or_insert(0) += 1;
                map
            });
        let mut result = Vec::new();
        while result.len() != s.len() {
            for i in 0..26 {
                lookup.entry(i).and_modify(|count| {
                    if *count > 0 {
                        result.push(char::from_u32('a' as u32 + i).unwrap_or_default());
                        *count -= 1;
                    }
                });
            }
            for i in (0..26).rev() {
                lookup.entry(i).and_modify(|count| {
                    if *count > 0 {
                        result.push(char::from_u32('a' as u32 + i).unwrap_or_default());
                        *count -= 1;
                    }
                });
            }
        }
        result.into_iter().collect()
    }
}
