// Solved 2020-12-02 16:17
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.5 MB (78.95%)

int minOperations(int n) {
    return (n % 2) ? (n * n - 1) / 4 : (n * n) / 4;
}
