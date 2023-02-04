// Solved 2023-02-04
// Runtime: 35 ms (81.25%)
// Memory Usage: 3.5 MB (93.75%)

impl Solution {
    pub fn find_array(pref: Vec<i32>) -> Vec<i32> {
        let mut arr = Vec::with_capacity(pref.len());
        arr.push(pref[0]);
        for i in 1..pref.len() {
            arr.push(pref[i - 1] ^ pref[i]);
        }
        arr
    }
}
