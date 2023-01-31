// Solved 2023-01-31
// Runtime: 3 ms (100.00%)
// Memory Usage: 3.9 MB (76.19%)

impl Solution {
    pub fn get_common(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        let mut i1 = 0;
        let mut i2 = 0;
        while i1 < nums1.len() && i2 < nums2.len() {
            match nums1[i1].cmp(&nums2[i2]) {
                std::cmp::Ordering::Equal => return nums1[i1],
                std::cmp::Ordering::Less => i1 += 1,
                std::cmp::Ordering::Greater => i2 += 1,
            }
        }
        -1
    }
}
