// Solved 2020-11-22 11:25
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.8 MB (74.10%)

int locateMin(int* a, int s) {
    int x = 0;
    for (int i = 0; i < s; i++) {
        if (a[i] < a[x]) x = i;
    }
    return x;
}

void sort(int* a, int s) {
    int x, t;
    for (int i = 0; i < s; i++) {
        if (x = locateMin(a + i, s - i)) {
            t = a[i];
            a[i] = a[i + x];
            a[i + x] = t;
        }
    }
}

int heightChecker(int* heights, int heightsSize) {
    int i, *a = (int*)malloc(sizeof(int) * heightsSize), c = 0;
    memcpy(a, heights, sizeof(int) * heightsSize);
    // for (i = 0; i < heightsSize; i++) a[i] = heights[i];
    sort(a, heightsSize);
    for (i = 0; i < heightsSize; i++) {
        if (a[i] != heights[i]) c++;
    }
    free(a);
    return c;
}
