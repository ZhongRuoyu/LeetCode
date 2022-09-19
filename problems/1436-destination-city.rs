// Solved 2022-09-19
// Runtime: 3 ms (100.00%)
// Memory Usage: 2.2 MB (85.71%)

impl Solution {
    pub fn dest_city(paths: Vec<Vec<String>>) -> String {
        let from_cities = <std::collections::HashSet<_> as std::iter::FromIterator<_>>::from_iter(
            paths.iter().map(|path| path[0].to_string()),
        );
        paths
            .iter()
            .map(|path| &path[1])
            .find(|city| !from_cities.contains(*city))
            .unwrap()
            .to_string()
    }
}
