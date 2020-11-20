// Solved 2020-11-20 17:06
// Runtime: 0 ms (100.00%)
// Memory Usage: 6.7 MB (86.26%)

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize) {
    int *a = (int*)malloc(sizeof(int) * (*returnSize = numsSize)), x = 0;
    for (int i = 0; i < numsSize; i++) {
        a[i] = (x += nums[i]);
    }
    return a;
}
