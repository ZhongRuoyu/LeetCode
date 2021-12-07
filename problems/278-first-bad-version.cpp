// Solved 2021-12-07
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.9 MB (65.85%)

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
   public:
    int firstBadVersion(int n) {
        int start = 0;
        int end = n;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (isBadVersion(mid)) {
                end = mid;
            } else {
                start = mid;
            }
        }
        return end;
    }
};
