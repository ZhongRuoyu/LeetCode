// Solved 2021-03-08 10:12
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.9 MB (79.45%)

class Solution {
   public:
    string baseNeg2(int N) {
        string ans;
        if (N == 0) ans = "0";
        while (N) {
            ans.insert(ans.begin(), (N & 1) ? '1' : '0');
            N = -(N >> 1);
        }
        return ans;
    }
};
