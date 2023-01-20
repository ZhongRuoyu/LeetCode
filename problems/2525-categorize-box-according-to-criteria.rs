// Solved 2023-01-20
// Runtime: 1 ms (89.23%)
// Memory Usage: 1.9 MB (93.85%)

impl Solution {
    pub fn categorize_box(length: i32, width: i32, height: i32, mass: i32) -> String {
        let bulky = length >= 10_000
            || width >= 10_000
            || height >= 10_000
            || length as i64 * width as i64 * height as i64 >= 1_000_000_000;
        let heavy = mass >= 100;
        match (bulky, heavy) {
            (true, true) => String::from("Both"),
            (true, false) => String::from("Bulky"),
            (false, true) => String::from("Heavy"),
            (false, false) => String::from("Neither"),
        }
    }
}
