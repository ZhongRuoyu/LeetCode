// Solved 2020-12-20 08:17
// Runtime: 40 ms (93.65%)
// Memory Usage: 11.5 MB (79.37%)

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diStringMatch(char* S, int* returnSize) {
    int N = strlen(S), *ans = (int*)malloc((*returnSize = N + 1) * sizeof(int)),
        x = 0, y = N;
    for (int i = 0; i <= N; i++) {
        ans[i] = (S[i] == 'I') ? x++ : y--;
    }
    return ans;
}
