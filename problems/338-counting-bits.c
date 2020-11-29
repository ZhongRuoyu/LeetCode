// Solved 2020-11-29 11:47
// Runtime: 40 ms (90.48%)
// Memory Usage: 10.4 MB (99.52%)

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize) {
    int* a = (int*)malloc(sizeof(int) * (*returnSize = num + 1));
    a[0] = 0;
    for (int i = 1; i <= num; i++) {
        a[i] = a[i / 2] + i % 2;
        // a bit twiddling trick: a[i] = a[i & (i - 1)] + 1;
        // (i & (i - 1)) drops the least significant 1
    }
    return a;
}
