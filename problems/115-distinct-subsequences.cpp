// Solved 2022-01-13
// Runtime: 8 ms (95.45%)
// Memory Usage: 10.6 MB (79.10%)

class Solution {
   public:
    int numDistinct(string s, string t) {
        unsigned dp[s.length() + 1][t.length() + 1];
        for (size_t i = 0; i != s.length() + 1; ++i) {
            dp[i][0] = 1;
        }
        for (size_t j = 0; j != t.length(); ++j) {
            dp[0][j + 1] = 0;
        }
        for (size_t i = 0; i != s.length(); ++i) {
            for (size_t j = 0; j != t.length(); ++j) {
                if (s[i] == t[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + dp[i][j + 1];
                } else {
                    dp[i + 1][j + 1] = dp[i][j + 1];
                }
            }
        }
        return dp[s.length()][t.length()];
    }
};
