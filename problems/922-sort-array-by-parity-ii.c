// Solved 2020-11-24 12:11
// Runtime: 64 ms (90.59%)
// Memory Usage: 13.6 MB (22.35%)

void swap(int* a, int x, int y) {
    int t = a[x];
    a[x] = a[y];
    a[y] = t;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* A, int ASize, int* returnSize) {
    int *ar = (int*)malloc(sizeof(int) * (*returnSize = ASize)), l = 0, r = 1;
    ar = memcpy(ar, A, sizeof(int) * ASize);
    while (1) {
        while ((l < ASize) && (ar[l] % 2 == 0)) l += 2;
        while ((r < ASize) && (ar[r] % 2 == 1)) r += 2;
        if ((l >= ASize) || (r >= ASize)) break;
        swap(ar, l, r);
    }
    return ar;
}
