// Solved 2021-06-04 10:29
// Runtime: 4 ms (88.23%)
// Memory Usage: 6.9 MB (84.39%)

class Solution {
   public:
    int minOperations(string s) {
        int c = 0;
        for (int i = 0; i != s.size(); ++i) {
            c += (s[i] - '0' != i % 2);
        }
        return min(c, static_cast<int>(s.size()) - c);
    }
};
