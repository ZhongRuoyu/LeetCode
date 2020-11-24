// Solved 2020-11-24 10:30
// Runtime: 4 ms (94.87%)
// Memory Usage: 6.9 MB (72.65%)

int locNextSpace(char* s) {
    int x = 0;
    while (s[x] != ' ' && s[x] != '\0') x++;
    return x;
}

char* reverseWords(char* s) {
    int i = 0, j, x, t;
    while (s[i]) {
        x = locNextSpace(s + i);
        for (j = 0; 2 * j < x; j++) {
            t = s[i + j];
            s[i + j] = s[i + x - 1 - j];
            s[i + x - 1 - j] = t;
        }
        i += s[i + x] ? ++x : x;
    }
    return s;
}
