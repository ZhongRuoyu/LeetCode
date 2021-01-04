// Solved 2021-01-05 07:47
// Runtime: 4 ms (97.09%)
// Memory Usage: 6.8 MB (73.26%)

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 0) return 0;
    int minprice = prices[0], maxprofit = 0;
    for (int i = 1; i < pricesSize; ++i) {
        if (prices[i] < minprice) {
            minprice = prices[i];
        } else if (prices[i] - minprice > maxprofit) {
            maxprofit = prices[i] - minprice;
        }
    }
    return maxprofit;
}
