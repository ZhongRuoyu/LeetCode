// Solved 2021-01-18 09:33
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.8 MB (97.13%)

class Solution {
   public:
    bool hasAlternatingBits(int n) {
        int prev = n & 1;
        while (n >>= 1) {
            if ((n & 1) == prev) return false;
            prev = n & 1;
        }
        return true;
    }
};
