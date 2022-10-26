// Solved 2022-10-26
// Runtime: 11 ms (88.44%)
// Memory Usage: 2.1 MB (91.91%)

impl Solution {
    pub fn coin_change(coins: Vec<i32>, amount: i32) -> i32 {
        let mut dp = vec![0; amount as usize + 1];

        for curr_amount in 1..=amount {
            let mut curr_amount_coins = i32::MAX - 1;
            for coin_amount in coins.iter() {
                if curr_amount - coin_amount >= 0 {
                    curr_amount_coins = std::cmp::min(
                        curr_amount_coins,
                        dp[(curr_amount - coin_amount) as usize] + 1,
                    );
                }
            }
            dp[curr_amount as usize] = curr_amount_coins;
        }

        if dp[amount as usize] <= amount {
            dp[amount as usize]
        } else {
            -1
        }
    }
}
