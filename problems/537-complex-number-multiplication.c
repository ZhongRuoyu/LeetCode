// Solved 2020-11-23 13:06
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.4 MB (90.91%)

char *complexNumberMultiply(char *a, char *b) {
    char *r = (char *)malloc(sizeof(char) * 13);
    int a1, a2, b1, b2;
    sscanf(a, "%d+%di", &a1, &a2);
    sscanf(b, "%d+%di", &b1, &b2);
    sprintf(r, "%d+%di", a1 * b1 - a2 * b2, a1 * b2 + a2 * b1);
    return r;
}
