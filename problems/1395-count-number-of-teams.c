// Solved 2020-11-21 10:48
// Runtime: 4 ms (88.41%)
// Memory Usage: 6 MB (74.64%)

int numTeams(int* rating, int ratingSize) {
    int i, j, ls, lg, rs, rg, c = 0;
    for (i = 1; i < ratingSize - 1; i++) {
        ls = lg = rs = rg = 0;
        for (j = 0; j < i; j++) {
            if (rating[j] < rating[i]) {
                ls++;
            } else if (rating[j] > rating[i]) {
                lg++;
            }
        }
        for (j = i + 1; j < ratingSize; j++) {
            if (rating[i] < rating[j]) {
                rg++;
            } else if (rating[i] > rating[j]) {
                rs++;
            }
        }
        c += ls * rg + lg * rs;
    }
    return c;
}
