// Solved 2022-10-14
// Runtime: 0 ms (100.00%)
// Memory Usage: 2.1 MB (92.86%)

impl Solution {
    pub fn final_prices(prices: Vec<i32>) -> Vec<i32> {
        let mut prices = prices;
        let mut stack = Vec::new();
        for i in 0..prices.len() {
            while !stack.is_empty() {
                let last = *stack.last().unwrap_or(&0);
                if prices[last] < prices[i] {
                    break;
                }
                prices[last] -= prices[i];
                stack.pop();
            }
            stack.push(i);
        }
        prices
    }
}
