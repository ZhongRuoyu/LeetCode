// Solved 2022-10-06
// Runtime: 12 ms (85.62%)
// Memory Usage: 4.1 MB (99.35%)

impl Solution {
    pub fn xor_all_nums(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        let mut xor = 0;
        if nums1.len() % 2 == 1 {
            nums2.iter().for_each(|&num| xor ^= num);
        }
        if nums2.len() % 2 == 1 {
            nums1.iter().for_each(|&num| xor ^= num);
        }
        xor
    }
}
