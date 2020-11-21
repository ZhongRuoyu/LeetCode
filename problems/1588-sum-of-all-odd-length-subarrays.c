// Solved 2020-11-21 11:25
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.9 MB (59.57%)

int sumOddLengthSubarrays(int* arr, int arrSize) {
    int i, j, c, s = 0;
    for (i = 0; i < arrSize; i++) {
        c = ((arrSize - i - 1) >> 1) + 1;
        s += arr[i] * (c--);
        for (j = i + 1; c && j < arrSize; j++) {
            s += arr[j] * c;
            if (!((j - i) % 2)) c--;
        }
    }
    return s;
}
