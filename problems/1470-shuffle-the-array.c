// Solved 2020-11-20 17:04
// Runtime: 4 ms (100.00%)
// Memory Usage: 7.1 MB (51.86%)

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize) {
    int* a = (int*)malloc(sizeof(int) * (*returnSize = numsSize));
    for (int i = 0; i < n; i++) {
        a[i << 1] = nums[i];
        a[(i << 1) + 1] = nums[n + i];
    }
    return a;
}
