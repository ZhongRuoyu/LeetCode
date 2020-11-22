// Solved 2020-11-22 10:41
// Runtime: 4 ms (91.75%)
// Memory Usage: 6 MB (91.75%)

int findNumbers(int* nums, int numsSize) {
    int d, x, c = 0;
    for (int i = 0; i < numsSize; i++) {
        d = 0;
        x = nums[i];
        while (x) {
            x /= 10;
            d++;
        }
        if (!(d % 2)) c++;
    }
    return c;
}
