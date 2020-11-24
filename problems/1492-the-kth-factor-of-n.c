// Solved 2020-11-24 10:37
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.4 MB (73.68%)

int kthFactor(int n, int k) {
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) k--;
        if (!k) return i;
    }
    return -1;
}
