// Solved 2022-12-05
// Runtime: 159 ms (100.00%)
// Memory Usage: 27.9 MB (100.00%)

impl Solution {
    pub fn evaluate(s: String, knowledge: Vec<Vec<String>>) -> String {
        let knowledge = knowledge
            .into_iter()
            .map(|entry| (entry[0].to_owned(), entry[1].to_owned()))
            .collect::<std::collections::HashMap<_, _>>();
        let mut result = String::new();
        let mut key = String::new();
        let mut is_key = false;
        for ch in s.chars() {
            match ch {
                '(' => {
                    key = String::new();
                    is_key = true;
                }
                ')' => {
                    let value = knowledge
                        .get(&key)
                        .map_or_else(|| String::from("?"), |value| value.to_owned());
                    result.extend(value.chars());
                    is_key = false;
                }
                _ => {
                    if is_key {
                        key.push(ch);
                    } else {
                        result.push(ch);
                    }
                }
            }
        }
        result
    }
}
