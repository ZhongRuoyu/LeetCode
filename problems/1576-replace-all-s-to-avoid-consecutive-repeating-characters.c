// Solved 2020-11-26 11:03
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.7 MB (51.11%)

void decrement(char* c, char d) {
    *c = d - 1;
    if (*c < 'a') *c = 'z';
}

char* modifyString(char* s) {
    int i, j, m = strlen(s);
    for (i = 0; i < m; i++) {
        if (s[i] == '?') {
            decrement(&s[i], s[i + 1]);
            if (i && (s[i - 1] == s[i])) {
                decrement(&s[i], s[i]);
            }
            for (j = i + 1; s[j] == '?'; j++) {
                decrement(&s[j], s[j - 1]);
            }
            if (s[j - 1] == s[j]) {
                decrement(&s[j - 1], s[j]);
            }
            i = j;
        }
    }
    return s;
}
