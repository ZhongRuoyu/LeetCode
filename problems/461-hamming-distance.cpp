// Solved 2021-01-19 08:50
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.8 MB (96.43%)

class Solution {
   public:
    int hammingDistance(int x, int y) {
        int ans = 0, n = x ^ y;
        while (n) {
            ans += (n & 1);
            n >>= 1;
        }
        return ans;
    }
};
