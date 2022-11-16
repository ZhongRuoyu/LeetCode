// Solved 2022-11-16
// Runtime: 0 ms (100.00%)
// Memory Usage: 2.1 MB (92.59%)

impl Solution {
    pub fn full_justify(words: Vec<String>, max_width: i32) -> Vec<String> {
        let mut result = Vec::new();
        let mut begin_index = 0;
        while begin_index < words.len() {
            let (end_index, char_count) = Self::get_next_line(&words, max_width, begin_index);
            result.push(Self::justify_line(
                &words,
                max_width,
                begin_index,
                end_index,
                char_count,
            ));
            begin_index = end_index;
        }
        result
    }

    fn get_next_line(words: &Vec<String>, max_width: i32, begin_index: usize) -> (usize, usize) {
        let mut next_index = begin_index + 1;
        let mut char_count = words[begin_index].chars().count();
        while next_index < words.len() {
            let next_word_length = words[next_index].chars().count();
            let line_min_width = char_count + next_word_length + (next_index - begin_index);
            if line_min_width > max_width as usize {
                break;
            }
            char_count += next_word_length;
            next_index += 1;
            if line_min_width == max_width as usize {
                break;
            }
        }
        (next_index, char_count)
    }

    fn justify_line(
        words: &Vec<String>,
        max_width: i32,
        begin_index: usize,
        end_index: usize,
        chars_in_line: usize,
    ) -> String {
        if end_index - begin_index <= 1 || end_index == words.len() {
            let mut line = words[begin_index..end_index].join(" ");
            line.push_str(" ".repeat(max_width as usize - line.len()).as_str());
            return line;
        }
        let slot_count = end_index - begin_index - 1;
        let space_count = max_width as usize - chars_in_line;
        let spaces_per_slot = space_count / slot_count;
        let mut extra_spaces = space_count % slot_count;
        let mut line = String::new();
        for word_index in begin_index..end_index {
            line.push_str(&words[word_index]);
            if word_index < end_index - 1 {
                if extra_spaces > 0 {
                    line.push_str(" ".repeat(spaces_per_slot + 1).as_str());
                    extra_spaces -= 1;
                } else {
                    line.push_str(" ".repeat(spaces_per_slot).as_str());
                }
            }
        }
        line
    }
}
