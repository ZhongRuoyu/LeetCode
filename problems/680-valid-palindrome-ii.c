// Solved 2020-12-01 12:11
// Runtime: 12 ms (92.04%)
// Memory Usage: 9.1 MB (86.73%)

bool isPalindrome(char* s, int l, int r) {
    while (l <= r) {
        if (s[l++] != s[r--]) return false;
    }
    return true;
}

bool validPalindrome(char* s) {
    int l = 0, r = strlen(s) - 1;
    while (l <= r) {
        if (s[l] != s[r]) {
            if (isPalindrome(s, l + 1, r)) {
                return true;
            }
            if (isPalindrome(s, l, r - 1)) {
                return true;
            }
            return false;
        }
        l++;
        r--;
    }
    return true;
}
