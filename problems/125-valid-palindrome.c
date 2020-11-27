// Solved 2020-11-27 08:33
// Runtime: 0 ms (100.00%)
// Memory Usage: 6.3 MB (79.84%)

bool isPalindrome(char* s) {
    int l = 0, r = strlen(s) - 1;
    while (l < r) {
        if (!isalnum(s[l])) {
            l++;
            continue;
        }
        if (!isalnum(s[r])) {
            r--;
            continue;
        }
        if (tolower(s[l++]) != tolower(s[r--])) return false;
    }
    return true;
}
