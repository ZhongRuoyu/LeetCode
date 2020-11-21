// Solved 2020-11-21 10:37
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.7 MB (54.91%)

int balancedStringSplit(char* s) {
    int c = 0, l = 0, r = 0;
    for (int i = 0; s[i]; i++) {
        (s[i] == 'L') ? l++ : r++;
        if (l && (l == r)) {
            c++;
            l = r = 0;
        }
    }
    return c;
}
