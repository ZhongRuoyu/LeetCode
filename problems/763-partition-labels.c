// Solved 2020-11-22 10:58
// Runtime: 4 ms (72.07%)
// Memory Usage: 5.6 MB (85.59%)

int locateNext(char* target) {
    int nextIndex, i, contains;
    for (nextIndex = 1; target[nextIndex]; nextIndex++) {
        contains = 0;
        for (i = 0; i < nextIndex; i++) {
            if (strchr(target + nextIndex, target[i])) {
                contains++;
                break;
            }
        }
        if (!contains) break;
    }
    return nextIndex;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* partitionLabels(char* S, int* returnSize) {
    int* a = (int*)malloc(sizeof(int) * 26);
    *returnSize = 0;
    while (*S) {
        S += (a[(*returnSize)++] = locateNext(S));
    }
    return a;
}
