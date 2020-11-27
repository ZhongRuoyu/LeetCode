// Solved 2020-11-27 08:36
// Runtime: 8 ms (100.00%)
// Memory Usage: 6.5 MB (64.53%)

int countPrimes(int n) {
    if (n <= 2) return 0;
    bool a[n / 2];
    // a boolean table for 2 and odd numbers greater than 1
    // {2, 3, 5, 7, 9, 11, 13, ...}
    // the rationale is clear when a table is drawed
    memset(a, true, sizeof(bool) * (n / 2));
    int i, j, c = 1;
    for (i = 3; i * i < n; i += 2) {
        if (!a[i / 2]) continue;
        for (j = 3 * i / 2; j < n / 2; j += i) {
            a[j] = false;
        }
    }
    for (i = 1; i < n / 2; i++) {
        if (a[i]) c++;
    }
    return c;
}
