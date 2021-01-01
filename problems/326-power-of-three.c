// Solved 2021-01-01 11:13
// Runtime: 8 ms (90.46%)
// Memory Usage: 6.2 MB (65.15%)

bool isPowerOfThree(int n) {
    if (n == 1) return true;
    return (n > 0) && (n % 3 == 0) && isPowerOfThree(n / 3);
}
