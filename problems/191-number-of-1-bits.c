// Solved 2021-01-02 11:23
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.4 MB (99.49%)

int hammingWeight(uint32_t n) {
    int ans = 0;
    while (n) {
        ans += (n & 1);
        n >>= 1;
    }
    return ans;
}
