// Solved 2020-12-09 12:28
// Runtime: 16 ms (88.58%)
// Memory Usage: 7.1 MB (99.80%)

int singleNumber(int* nums, int numsSize) {
    int x = 0;
    for (int i = 0; i < numsSize; i++) {
        x ^= nums[i];
        // any number xor itself is 0
    }
    return x;
}
