// Solved 2020-11-25 11:29
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.9 MB (90.91%)

int gcd(int x, int y) {
    int s = (x <= y) ? x : y;
    for (int i = s; i; i--) {
        if (!(x % i) && !(y % i)) return i;
    }
    return 0;
}

char* gcdOfStrings(char* str1, char* str2) {
    int l1 = strlen(str1), l2 = strlen(str2);
    if (l1 <= l2) {
        int t = l1;
        char* p = str1;
        l1 = l2;
        str1 = str2;
        l2 = t;
        str2 = p;
    }  // now str2 is the shorter one
    int g = gcd(l1, l2), i, j, d;
    char* r;
    for (i = g; i; i--) {  // size of substring
        d = 1;
        for (j = i; j + i <= l2; j += i) {  // check if substring divides str2
            if (strncmp(str2, str2 + j, i)) {
                d--;
                break;
            }
        }
        if (!d) continue;
        for (j = 0; j + i <= l1; j += i) {  // check if substring divides str1
            if (strncmp(str2, str1 + j, i)) {
                d--;
                break;
            }
        }
        if (d) break;
    }
    r = (char*)malloc(sizeof(char) * (i + 1));
    strncpy(r, str2, i);
    r[i] = '\0';
    return r;
}
