// Solved 2023-01-25
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (92.31%)

impl Solution {
    pub fn is_long_pressed_name(name: String, typed: String) -> bool {
        let name = name.chars().collect::<Vec<_>>();
        let typed = typed.chars().collect::<Vec<_>>();
        let mut i_name = 0;
        let mut i_typed = 0;
        while i_name < name.len() && i_typed < typed.len() {
            if name[i_name] != typed[i_typed] {
                return false;
            }
            let mut letter_count = 1;
            while i_name + letter_count < name.len() && name[i_name + letter_count] == name[i_name]
            {
                letter_count += 1;
            }
            let mut typed_count = 1;
            while i_typed + typed_count < typed.len()
                && typed[i_typed + typed_count] == typed[i_typed]
            {
                typed_count += 1;
            }
            if typed_count < letter_count {
                return false;
            }
            i_name += letter_count;
            i_typed += typed_count;
        }
        i_name == name.len() && i_typed == typed.len()
    }
}
