// Solved 2020-11-21 10:27
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.6 MB (61.15%)

int xorOperation(int n, int start) {
    int x = start;
    for (int i = start + 2; i < start + (n << 1); i += 2) {
        x ^= i;
    }
    return x;
}
