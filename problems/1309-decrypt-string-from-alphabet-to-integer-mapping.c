// Solved 2020-11-22 11:11
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.6 MB (75.64%)

char* freqAlphabets(char* s) {
    int l = strlen(s);
    char *r = (char*)malloc(sizeof(char) * (l + 1)), *p = r;
    for (int i = 0; i < l; i++) {
        if (s[i] != '#') {
            *(p++) = s[i] + 48;  // (s[i] - '0' + 1) + 'a'
        } else {
            p -= 2;
            *(p++) = 10 * s[i - 2] + s[i - 1] - 432;  // 10 * (s[i - 2] - '0') + s[i - 1] + 48
        }
    }
    *p = '\0';
    return r;
}
