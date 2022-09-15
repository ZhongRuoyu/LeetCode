// Solved 2022-09-15
// Runtime: 51 ms (85.13%)
// Memory Usage: 9.1 MB (93.24%)

impl Solution {
    pub fn garbage_collection(garbage: Vec<String>, travel: Vec<i32>) -> i32 {
        let mut distances = vec![0; travel.len() + 1];
        for i in 0..travel.len() {
            distances[i + 1] = distances[i] + travel[i];
        }
        let mut count = 0;
        let mut last_m = 0;
        let mut last_p = 0;
        let mut last_g = 0;
        for (i, house) in garbage.iter().enumerate() {
            count += house.chars().count() as i32;
            house.chars().for_each(|ch| match ch {
                'M' => last_m = i,
                'P' => last_p = i,
                'G' => last_g = i,
                _ => (),
            })
        }
        count + distances[last_m] + distances[last_p] + distances[last_g]
    }
}
