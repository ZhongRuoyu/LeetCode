// Solved 2022-09-05
// Runtime: 76 ms (97.14%)
// Memory Usage: 3.6 MB (100.00%)

impl Solution {
    pub fn pivot_array(nums: Vec<i32>, pivot: i32) -> Vec<i32> {
        let mut less = 0;
        let mut equal = 0;
        for num in &nums {
            match num.cmp(&pivot) {
                std::cmp::Ordering::Less => less += 1,
                std::cmp::Ordering::Equal => equal += 1,
                _ => (),
            }
        }

        let mut greater = less + equal;
        let mut equal = less;
        let mut less = 0;
        let mut result = vec![0; nums.len()];
        for num in &nums {
            match num.cmp(&pivot) {
                std::cmp::Ordering::Less => {
                    result[less] = *num;
                    less += 1;
                }
                std::cmp::Ordering::Equal => {
                    result[equal] = *num;
                    equal += 1;
                }
                std::cmp::Ordering::Greater => {
                    result[greater] = *num;
                    greater += 1;
                }
            }
        }

        result
    }
}
