// Solved 2020-11-25 11:15
// Runtime: 4 ms (88.78%)
// Memory Usage: 5.8 MB (60.20%)

bool threeConsecutiveOdds(int* arr, int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % 2) {
            if ((i + 1 < arrSize) && (arr[i + 1] % 2)) {
                if ((i + 2 < arrSize) && (arr[i + 2] % 2)) {
                    return true;
                } else {
                    i += 2;
                }
            } else {
                i++;
            }
        }
    }
    return false;
}
