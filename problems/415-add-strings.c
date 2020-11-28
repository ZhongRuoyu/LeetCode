// Solved 2020-11-28 09:11
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.9 MB (59.84%)

char add(char* sum, const char digit1, const char digit2) {
    int s = *sum + digit1 + digit2 - 144;  // (*sum - '0') + (digit1 - '0') + (digit2 - '0')
    *sum = s % 10 + '0';                   // returns sum
    return (s / 10 + '0');                 // returns carry
}

char* addStrings(char* num1, char* num2) {
    int i,
        l1 = strlen(num1),                      // length of num1, excluding the trailing null
        l2 = strlen(num2),                      // length of num2, excluding the trailing null
        ls = (l1 >= l2) ? (l1 + 1) : (l2 + 1);  // length of sum, excluding the trailing null
    char* sum = (char*)malloc(sizeof(char) * (ls + 1));
    memset(sum, '0', sizeof(char) * ls);
    sum[ls] = '\0';
    for (i = 1; (l1 >= i) && (l2 >= i); i++) {
        sum[ls - i - 1] = add(&sum[ls - i], num1[l1 - i], num2[l2 - i]);
    }
    for (; (l1 >= i); i++) {
        sum[ls - i - 1] = add(&sum[ls - i], num1[l1 - i], '0');  // handles the rest when (l1 > l2)
    }
    for (; (l2 >= i); i++) {
        sum[ls - i - 1] = add(&sum[ls - i], num2[l2 - i], '0');  // handles the rest when (l2 > l1)
    }
    if (*sum == '0') ++sum;  // handles the leading zero, if exists
    return sum;
}
