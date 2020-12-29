// Solved 2020-12-29 09:30
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.5 MB (71.37%)

int reverse(int x) {
    int res = 0;
    while (x) {
        if (res > INT_MAX / 10 || res < INT_MIN / 10) return 0;
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}
