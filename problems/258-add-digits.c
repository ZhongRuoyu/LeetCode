// Solved 2020-12-14 12:21
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.4 MB (92.53%)

int addDigits(int num) {
    // https://en.wikipedia.org/wiki/Digital_root#Congruence_formula
    return (1 + (num - 1) % 9);
}
