// Solved 2020-11-20 18:19
// Runtime: 36 ms (64.60%)
// Memory Usage: 10.3 MB (80.29%)

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decompressRLElist(int* nums, int numsSize, int* returnSize) {
    int *a, *p, i, j;
    *returnSize = 0;
    for (i = 0; i < numsSize; i += 2) {
        *returnSize += nums[i];
    }
    p = (a = (int*)malloc(sizeof(int) * (*returnSize)));
    for (i = 0; i < numsSize; i += 2) {
        for (j = 0; j < nums[i]; j++) {
            *(p++) = nums[i + 1];
        }
    }
    return a;
}
