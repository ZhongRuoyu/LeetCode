// Solved 2020-12-25 10:22
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.8 MB (77.66%)

char* addBinary(char* a, char* b) {
    int i, sum, la = strlen(a), lb = strlen(b);
    if (la < lb) {
        int t = la;
        la = lb;
        lb = t;
        char* c = a;
        a = b;
        b = c;
    }  // now a is longer

    int lans = la + 1;
    char* ans = (char*)malloc((lans + 1) * sizeof(char));
    ans[lans - 1] = '0';

    for (i = 1; i <= lb; i++) {
        sum = a[la - i] + b[lb - i] + ans[lans - i] - 144;
        // a[la - i] - '0' + b[lb - i] - '0' + ans[lans - i] - '0'
        ans[lans - i] = sum % 2 + '0';
        ans[lans - i - 1] = sum / 2 + '0';
    }
    for (; i <= la; i++) {
        sum = a[la - i] + ans[lans - i] - 96;
        // a[la - i] - '0' + ans[lans - i] - '0'
        ans[lans - i] = sum % 2 + '0';
        ans[lans - i - 1] = sum / 2 + '0';
    }

    ans[lans] = '\0';
    if (ans[0] == '0') ans++;
    return ans;
}
