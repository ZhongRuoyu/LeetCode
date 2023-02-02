// Solved 2023-02-02
// Runtime: 22 ms (80.60%)
// Memory Usage: 2.8 MB (94.30%)

impl Solution {
    pub fn sort_the_students(score: Vec<Vec<i32>>, k: i32) -> Vec<Vec<i32>> {
        let mut score = score;
        score.sort_unstable_by_key(|student| std::cmp::Reverse(student[k as usize]));
        score
    }
}
