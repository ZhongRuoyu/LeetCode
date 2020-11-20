// Solved 2020-11-20 16:56
// Runtime: 4 ms (86.09%)
// Memory Usage: 6.5 MB (36.42%)

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    bool* a = (bool*)malloc(sizeof(bool) * (*returnSize = candiesSize));
    int maxIndex = 0;
    for (int i = 1; i < candiesSize; i++) {
        if (candies[i] > candies[maxIndex]) {
            maxIndex = i;
        }
    }
    for (int i = 0; i < candiesSize; i++) {
        a[i] = (candies[i] + extraCandies >= candies[maxIndex]);
    }
    return a;
}
