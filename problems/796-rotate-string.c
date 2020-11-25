// Solved 2020-11-25 11:19
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.5 MB (92.68%)

void shift(char *s) {
    char c = *s;
    while (*(++s)) *(s - 1) = *s;
    *(--s) = c;
}

bool rotateString(char *A, char *B) {
    int n = strlen(A);
    if (n != strlen(B)) return false;
    if (!n) return true;
    for (int i = 0; i < n; i++) {
        if (!strncmp(A, B, n)) return true;
        shift(A);
    }
    return false;
}
