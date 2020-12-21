// Solved 2020-12-21 08:37
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.4 MB (87.86%)

int maximum69Number(int num) {
    int x = 1, add = 0;
    while (num > x) {
        if (((num / x) % 10) == 6) add = x * 3;
        x *= 10;
    }
    return (num + add);
}
