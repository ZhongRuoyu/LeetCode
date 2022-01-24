// Solved 2022-01-24
// Runtime: 0 ms (100.00%)
// Memory Usage: 6.2 MB (73.17%)

class Solution {
   public:
    int countGoodSubstrings(string s) {
        int count = 0;
        for (int i = 0; i + 2 < s.length();) {
            if (s[i] == s[i + 1] || s[i] == s[i + 2]) {
                i += 1;
            } else if (s[i + 1] == s[i + 2]) {
                i += 2;
            } else {
                ++count;
                ++i;
            }
        }
        return count;
    }
};
