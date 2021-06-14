// Solved 2021-06-14
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.8 MB (94.77%)

class Solution {
   public:
    int sumBase(int n, int k) {
        int res(0);
        for (; n; n /= k) res += n % k;
        return res;
    }
};
