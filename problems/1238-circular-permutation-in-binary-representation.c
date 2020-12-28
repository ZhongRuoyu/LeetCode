// Solved 2020-12-28 10:19
// Runtime: 200 ms (96.15%)
// Memory Usage: 34.7 MB (84.62%)

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* circularPermutation(int n, int start, int* returnSize) {
    int* ans = (int*)malloc((*returnSize = (1 << n)) * sizeof(int));
    for (unsigned i = 0; i < (1 << n); i++) {
        ans[i] = start ^ (i ^ (i >> 1));
        // modified gray code
        // https://en.wikipedia.org/wiki/Gray_code#Converting_to_and_from_Gray_code
    }
    return ans;
}
