// Solved 2020-12-19 11:26
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.5 MB (93.89%)

int trailingZeroes(int n) {
    int ans = 0;
    while (n) ans += n /= 5;
    return ans;
}
