// Solved 2020-11-20 16:45
// Runtime: 8 ms (70.56%)
// Memory Usage: 6.6 MB (86.26%)

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize) {
    int *a = malloc(sizeof(int) * (*returnSize = numsSize)), x = 0;
    for (int i = 0; i < numsSize; i++) {
        a[i] = (x += nums[i]);
    }
    return a;
}
