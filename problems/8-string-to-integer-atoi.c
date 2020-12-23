// Solved 2020-12-23 11:10
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.7 MB (71.40%)

int myAtoi(char *s) {
    int r = 0,
        sign = 1;  // 0 for negative, 1 for non-negative
    while (isblank(*s)) s++;
    if ((*s == '-') || (*s == '+')) {
        sign = (*(s++) == '+');
    }
    while (isdigit(*s)) {
        if ((r > INT_MAX / 10) ||
            ((r == INT_MAX / 10) &&
             (*s - '0' > 7))) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        r = r * 10 + (*(s++) - '0');
    }
    return sign ? r : -r;
}
