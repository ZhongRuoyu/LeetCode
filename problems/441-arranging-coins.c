// Solved 2020-12-16 11:51
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.5 MB (97.50%)

int arrangeCoins(int n) {
    // (x * (x + 1)) / 2 <= n
    // floor is done by casting
    return (int)(((sqrt(8.0 * n + 1.0)) / 2.0) - 0.5);
}
