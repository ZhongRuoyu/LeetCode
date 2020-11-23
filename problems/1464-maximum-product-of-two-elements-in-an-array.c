// Solved 2020-11-23 12:46
// Runtime: 0 ms (100.00%)
// Memory Usage: 6.1 MB (64.29%)

int locateMax(int *l, int s, int excl) {
    int x = excl ? 0 : 1;
    for (int i = 1; i < s; i++) {
        if (l[i] > l[x] && i != excl) x = i;
    }
    return x;
}

int maxProduct(int* nums, int numsSize) {
    int i = locateMax(nums, numsSize, -1), j = locateMax(nums, numsSize, i);
    return (nums[i] - 1) * (nums[j] - 1);
}
