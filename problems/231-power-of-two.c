// Solved 2020-12-04 16:15
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.5 MB (90.99%)

bool isPowerOfTwo(int n) {
    return (n > 0) && !(n & (n - 1));
}
