// Solved 2020-11-26 10:51
// Runtime: 8 ms (70.62%)
// Memory Usage: 5.9 MB (79.64%)

bool isPalindrome(int x) {
    if ((x < 0) || (!(x % 10) && x)) return false;
    int r = 0;
    while (x > r) {
        r = r * 10 + x % 10;
        x /= 10;
    }
    if ((x == r) || (x == r / 10)) return true;
    return false;
}
