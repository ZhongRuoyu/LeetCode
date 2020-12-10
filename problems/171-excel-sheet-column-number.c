// Solved 2020-12-10 22:51
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.5 MB (89.47%)

int titleToNumber(char* s) {
    int ans = 0;
    do {
        // ans * 26 + *s - 'A' + 1
        // subtraction done first to prevent overflow
        ans = ans * 26 - 64 + *s;
    } while (*(++s));
    return ans;
}
