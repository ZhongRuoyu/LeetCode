// Solved 2022-09-20
// Runtime: 42 ms (93.94%)
// Memory Usage: 8.9 MB (77.27%)

impl Solution {
    pub fn find_smallest_set_of_vertices(n: i32, edges: Vec<Vec<i32>>) -> Vec<i32> {
        let mut reached = vec![false; n as usize];
        edges
            .iter()
            .for_each(|edge| reached[edge[1] as usize] = true);
        reached
            .iter()
            .enumerate()
            .filter(|(_, &x)| !x)
            .map(|(i, _)| i as i32)
            .collect()
    }
}
