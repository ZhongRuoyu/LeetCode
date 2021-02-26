// Solved 2021-02-26 09:47
// Runtime: 24 ms (96.87%)
// Memory Usage: 5.7 MB (96.18%)

class Solution {
   public:
    int concatenatedBinary(int n) {
        long long ans = 0;
        int shift = 0;
        for (int i = 1; i <= n; ++i) {
            if ((i & (i - 1)) == 0) ++shift;
            ans = ((ans << shift) | i) % 1000000007LL;
        }
        return ans;
    }
};
