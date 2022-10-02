// Solved 2022-10-02
// Runtime: 9 ms (88.46%)
// Memory Usage: 2.3 MB (91.54%)

impl Solution {
    pub fn sort_people(names: Vec<String>, heights: Vec<i32>) -> Vec<String> {
        let mut indices = (0..heights.len()).collect::<Vec<_>>();
        indices.sort_unstable_by_key(|index| std::cmp::Reverse(heights[*index]));
        indices
            .into_iter()
            .map(|index| names[index].clone())
            .collect()
    }
}
