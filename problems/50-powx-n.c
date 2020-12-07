// Solved 2020-12-07 15:21
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.4 MB (98.97%)

double myPow(double x, int n) {
    if (n == 0) return 1;
    if (n == INT_MIN) return myPow(1.0 / (x * x), -(n / 2));
    if (n < 0) return myPow(1.0 / x, -n);
    return ((n % 2) ? x : 1.0) * myPow(x * x, n / 2);
}
