// Solved 2020-11-20 17:35
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.5 MB (84.25%)

int numJewelsInStones(char* J, char* S) {
    int c = 0, i;
    while (*S) {
        for (i = 0; J[i]; i++) {
            if (J[i] == *S) {
                c++;
                break;
            }
        }
        S++;
    }
    return c;
}
