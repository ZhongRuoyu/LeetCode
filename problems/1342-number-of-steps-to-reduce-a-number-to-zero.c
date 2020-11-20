// Solved 2020-11-20 17:42
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.5 MB (68.05%)

int numberOfSteps(int num) {
    int c = 0;
    while (num) {
        if (num % 2) {
            num--;
        } else {
            num >>= 1;
        }
        c++;
    }
    return c;
}
