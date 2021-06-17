// Solved 2021-06-17
// Runtime: 0 ms (100.00%)
// Memory Usage: 6.1 MB (65.98%)

class Solution {
   public:
    int maxDepth(string s) {
        int res(0), cur(0);
        for (auto &ch : s) {
            if (ch == '(') {
                res = max(res, ++cur);
            } else if (ch == ')') {
                --cur;
            }
        }
        return res;
    }
};
