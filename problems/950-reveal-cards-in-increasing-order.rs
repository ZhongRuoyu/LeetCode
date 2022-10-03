// Solved 2022-10-03
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (83.33%)

impl Solution {
    pub fn deck_revealed_increasing(deck: Vec<i32>) -> Vec<i32> {
        let mut deck = deck;
        let mut indices = (0..deck.len()).collect::<std::collections::VecDeque<_>>();
        let mut result = vec![0; deck.len()];
        deck.sort_unstable();
        for card in deck {
            let index = indices.pop_front().unwrap_or_default();
            result[index] = card;
            if !indices.is_empty() {
                let front = indices.pop_front().unwrap_or_default();
                indices.push_back(front);
            }
        }
        result
    }
}
