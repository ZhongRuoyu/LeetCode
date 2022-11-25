// Solved 2022-11-25
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (99.00%)

impl Solution {
    pub fn convert_temperature(celsius: f64) -> Vec<f64> {
        vec![celsius + 273.15, celsius * 1.80 + 32.00]
    }
}
