// Solved 2022-09-04
// Runtime: 7 ms (100.00%)
// Memory Usage: 2.7 MB (100.00%)

impl Solution {
    pub fn number_of_beams(bank: Vec<String>) -> i32 {
        bank.iter()
            .map(|s| s.chars().filter(|&ch| ch != '0').count() as i32)
            .filter(|&x| x != 0)
            .collect::<Vec<_>>()
            .windows(2)
            .map(|x| x.iter().product::<i32>())
            .sum::<i32>()
    }
}
