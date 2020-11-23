// Solved 2020-11-23 12:52
// Runtime: 4 ms (98.99%)
// Memory Usage: 6.4 MB (72.73%)

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumZero(int n, int* returnSize) {
    int* a = (int*)malloc(sizeof(int) * (*returnSize = n));
    for (int i = 0; i < n; i++) {
        a[i] = -n / 2 + i;
    }
    if (!(n % 2)) a[n - 1] += n / 2;
    return a;
}
