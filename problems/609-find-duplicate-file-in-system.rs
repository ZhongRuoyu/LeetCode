// Solved 2022-12-02
// Runtime: 35 ms (100.00%)
// Memory Usage: 7.5 MB (100.00%)

impl Solution {
    pub fn find_duplicate(paths: Vec<String>) -> Vec<Vec<String>> {
        let mut files = std::collections::HashMap::new();
        for path in paths {
            let mut path_entries = path.split(" ").collect::<Vec<_>>();
            let directory = path_entries.remove(0);
            for file in path_entries {
                let file_entry = file.split_terminator(&['(', ')']).collect::<Vec<_>>();
                let filename = file_entry[0];
                let content = file_entry[1];
                files
                    .entry(String::from(content))
                    .or_insert_with(|| Vec::new())
                    .push([directory, filename].join("/"));
            }
        }
        files
            .into_iter()
            .filter(|(_content, filenames)| filenames.len() > 1)
            .map(|(_content, filenames)| filenames)
            .collect()
    }
}
