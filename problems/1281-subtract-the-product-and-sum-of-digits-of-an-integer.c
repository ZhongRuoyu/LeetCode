// Solved 2020-11-20 17:53
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.5 MB (76.03%)

int subtractProductAndSum(int n) {
    int s = 0, p = 1;
    while (n) {
        s += n % 10;
        p *= n % 10;
        n /= 10;
    }
    return (p - s);
}
