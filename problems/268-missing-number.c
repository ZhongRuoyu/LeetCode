// Solved 2020-12-15 11:05
// Runtime: 16 ms (90.12%)
// Memory Usage: 6.5 MB (77.98%)

int missingNumber(int* nums, int numsSize) {
    int x = numsSize;
    for (int i = 0; i < numsSize; i++) {
        x ^= i ^ nums[i];
        // any number xor itself is 0
    }
    return x;
}
