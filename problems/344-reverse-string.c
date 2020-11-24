// Solved 2020-11-24 10:33
// Runtime: 40 ms (99.31%)
// Memory Usage: 12.3 MB (97.93%)

void reverseString(char* s, int sSize) {
    char t;
    for (int i = 0; 2 * i < sSize; i++) {
        t = s[i];
        s[i] = s[sSize - 1 - i];
        s[sSize - 1 - i] = t;
    }
}
