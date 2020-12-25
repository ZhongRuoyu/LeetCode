// Solved 2020-12-26 06:55
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.5 MB (81.25%)

int clumsy(int N) {
    int ans = 0, sign = 1;
    while (N / 4) {
        ans += sign * (N * (N - 1) / (N - 2)) + (N - 3);
        sign = -1;
        N -= 4;
    }
    switch (N) {
        case 3:
            return (ans += sign * (3 * 2 / 1));
        case 2:
            return (ans += sign * (2 * 1));
        case 1:
            return (ans += sign * 1);
    }
    return ans;
}
