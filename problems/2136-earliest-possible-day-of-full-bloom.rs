// Solved 2023-02-05
// Runtime: 27 ms (100.00%)
// Memory Usage: 4.1 MB (100.00%)

impl Solution {
    pub fn earliest_full_bloom(plant_time: Vec<i32>, grow_time: Vec<i32>) -> i32 {
        let mut seeds = (0..grow_time.len()).collect::<Vec<_>>();
        seeds.sort_unstable_by_key(|&i| std::cmp::Reverse(grow_time[i]));
        let mut time = 0;
        let mut result = 0;
        for seed in seeds {
            time += plant_time[seed];
            result = result.max(time + grow_time[seed]);
        }
        result
    }
}

// Happy birthday
