// Solved 2021-06-09 23:02
// Runtime: 0 ms (100.00%)
// Memory Usage: 6 MB (93.55%)

class Solution {
   public:
    bool areAlmostEqual(string s1, string s2) {
        int c1(-1), c2(-1), c(0);
        for (int i = 0; i != s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                if (c1 == -1) {
                    c1 = s1[i], c2 = s2[i];
                } else {
                    if (c++ || !(c2 == s1[i] && c1 == s2[i])) return false;
                }
            }
        }
        return c1 == -1 || c == 1;
    }
};
