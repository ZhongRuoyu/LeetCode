// Solved 2022-09-14
// Runtime: 26 ms (92.31%)
// Memory Usage: 8.8 MB (100.00%)

impl Solution {
    pub fn find_center(edges: Vec<Vec<i32>>) -> i32 {
        if edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1] {
            edges[0][0]
        } else {
            edges[0][1]
        }
    }
}
