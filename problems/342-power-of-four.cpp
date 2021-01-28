// Solved 2021-01-28 10:30
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.8 MB (95.92%)

class Solution {
   public:
    bool isPowerOfFour(int n) {
        return ((n > 0) && ((n & (n - 1)) == 0) && (n % 3 == 1));
    }
};
