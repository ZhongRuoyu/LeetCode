// Solved 2021-05-24 10:00
// Runtime: 0 ms (100.00%)
// Memory Usage: 6 MB (95.83%)

class Solution {
   public:
    int numDecodings(string s) {
        if (s.size() == 1) return (s != "0");
        int a = 0, b = 1, c = 0;  // dynamic programming
        for (int i = 1; i <= s.size(); ++i) {
            c = 0;
            if (i >= 2 && s[i - 2] != '0' &&
                10 * (s[i - 2] - '0') + (s[i - 1] - '0') <= 26) {
                c += a;
            }
            if (s[i - 1] != '0') {
                c += b;
            }
            a = b, b = c;
        }
        return c;
    }
};
