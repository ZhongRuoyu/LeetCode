// Solved 2022-12-31
// Runtime: 4 ms (75.66%)
// Memory Usage: 2.4 MB (100.00%)

impl Solution {
    pub fn top_k_frequent(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let frequencies =
            nums.into_iter()
                .fold(std::collections::HashMap::new(), |mut map, num| {
                    map.entry(num).and_modify(|freq| *freq += 1).or_insert(1);
                    map
                });
        let unique_count = frequencies.len();
        let mut frequencies = frequencies
            .into_iter()
            .map(|(num, freq)| (freq, num))
            .collect();
        Self::quickselect(&mut frequencies, unique_count - k as usize, 0, unique_count);
        frequencies
            .into_iter()
            .skip(unique_count - k as usize)
            .map(|(_freq, num)| num)
            .collect()
    }

    fn quickselect(
        frequencies: &mut Vec<(i32, i32)>,
        target: usize,
        begin_index: usize,
        end_index: usize,
    ) {
        if begin_index == end_index || begin_index + 1 == end_index {
            return;
        }
        let pivot_index = Self::partition(
            frequencies,
            begin_index,
            end_index,
            begin_index + (end_index - begin_index) / 2,
        );
        match pivot_index.cmp(&target) {
            std::cmp::Ordering::Less => {
                Self::quickselect(frequencies, target, pivot_index + 1, end_index)
            }
            std::cmp::Ordering::Equal => (),
            std::cmp::Ordering::Greater => {
                Self::quickselect(frequencies, target, begin_index, pivot_index)
            }
        }
    }

    fn partition(
        frequencies: &mut Vec<(i32, i32)>,
        begin_index: usize,
        end_index: usize,
        pivot_index: usize,
    ) -> usize {
        let pivot_freq = frequencies[pivot_index];
        {
            let temp = frequencies[end_index - 1];
            frequencies[end_index - 1] = frequencies[pivot_index];
            frequencies[pivot_index] = temp;
        }

        let mut pivot_index = begin_index;
        for i in begin_index..end_index {
            if frequencies[i] < pivot_freq {
                let temp = frequencies[i];
                frequencies[i] = frequencies[pivot_index];
                frequencies[pivot_index] = temp;
                pivot_index += 1;
            }
        }

        {
            let temp = frequencies[end_index - 1];
            frequencies[end_index - 1] = frequencies[pivot_index];
            frequencies[pivot_index] = temp;
        }

        pivot_index
    }
}
