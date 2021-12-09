// Solved 2021-12-09
// Runtime: 104 ms (93.68%)
// Memory Usage: 93.4 MB (52.46%)

class Solution {
   public:
    int maxProfit(vector<int> &prices) {
        int min_price = prices.front();
        int max_profit = 0;
        for (size_t i = 1; i < prices.size(); ++i) {
            if (prices[i] < min_price) {
                min_price = prices[i];
            } else {
                max_profit = max(max_profit, prices[i] - min_price);
            }
        }
        return max_profit;
    }
};
