// Solved 2020-11-24 10:52
// Runtime: 8 ms (66.23%)
// Memory Usage: 7 MB (79.22%)

int attempt(char* s) {
    int x = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i + 1] == s[i]) i += 2;
        if (!(s[x++] = s[i])) i--;
    }
    s[x] = '\0';
    return x;
}

char* removeDuplicates(char* S) {
    while (strlen(S) != attempt(S)) continue;
    return S;
}
