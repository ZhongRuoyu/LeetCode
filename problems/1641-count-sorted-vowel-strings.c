// Solved 2020-12-03 14:20
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.4 MB (85.19%)

int countVowelStrings(int n) {
    return (n + 1) * (n + 2) * (n + 3) * (n + 4) / 24;
}
