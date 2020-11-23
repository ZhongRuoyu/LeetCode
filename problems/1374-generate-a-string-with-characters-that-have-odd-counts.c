// Solved 2020-11-23 12:58
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.9 MB (77.78%)

char *generateTheString(int n) {
    char *s = (char *)malloc(sizeof(char) * (n + 1));
    memset(s, 'a', sizeof(char) * n);
    if (!(n % 2)) s[0] = 'b';
    s[n] = '\0';
    return s;
}
