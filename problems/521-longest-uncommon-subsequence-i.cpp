// Solved 2021-01-14 08:19
// Runtime: 0 ms (100.00%)
// Memory Usage: 6 MB (100.00%)

class Solution {
   public:
    int findLUSlength(string a, string b) {
        if (a == b) return -1;
        return max(a.size(), b.size());
    }
};
