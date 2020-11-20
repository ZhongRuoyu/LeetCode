// Solved 2020-11-20 17:27
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.5 MB (75.86%)

char *defangIPaddr(char *address) {
    char *a = malloc(sizeof(char) * 22), *r = a;
    while (*address) {
        if (*address != '.') {
            *(a++) = *(address++);
        } else {
            *(a++) = '[';
            *(a++) = *(address++);
            *(a++) = ']';
        }
    }
    *a = '\0';
    return r;
}
