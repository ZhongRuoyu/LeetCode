// Solved 2022-09-03
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (100.00%)

impl Solution {
    pub fn watering_plants(plants: Vec<i32>, capacity: i32) -> i32 {
        let mut steps = 0;
        let mut amount = capacity;
        for (distance, plant) in plants.iter().enumerate() {
            let distance = distance as i32;
            steps += 1;
            if *plant > amount {
                steps += distance * 2;
                amount = capacity - plant;
            } else {
                amount -= plant;
            }
        }
        steps
    }
}
