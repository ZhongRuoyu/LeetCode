// Solved 2021-01-13 16:30
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.9 MB (100.00%)

class Solution {
   public:
    int climbStairs(int n) {
        if (n == 1 || n == 2) return n;
        int x = 1, y = 2, z = 3;
        for (int i = 4; i <= n; ++i) {
            x = y;
            y = z;
            z = x + y;
        }
        return z;
    }
};
