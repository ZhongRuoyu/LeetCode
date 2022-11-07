// Solved 2022-11-07
// Runtime: 21 ms (90.48%)
// Memory Usage: 4 MB (76.19%)

impl Solution {
    pub fn xor_queries(arr: Vec<i32>, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let mut prefix_xor = vec![0; arr.len() + 1];
        for i in 0..arr.len() {
            prefix_xor[i + 1] = prefix_xor[i] ^ arr[i];
        }
        queries
            .into_iter()
            .map(|query| prefix_xor[query[0] as usize] ^ prefix_xor[query[1] as usize + 1])
            .collect()
    }
}
