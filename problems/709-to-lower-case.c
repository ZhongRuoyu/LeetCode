// Solved 2020-11-22 10:44
// Runtime: 4 ms (100.00%)
// Memory Usage: 5.3 MB (90.91%)

char* toLowerCase(char* str) {
    char* r = str;
    while (*str) {
        if ((*str >= 'A') && (*str <= 'Z')) {
            *str += 32;  // 'a' - 'A'
        }
        str++;
    }
    return r;
}
