// Solved 2021-03-30 08:42
// Runtime: 0 ms (100.00%)
// Memory Usage: 6.3 MB (93.18%)

class Solution {
   public:
    int lengthOfLastWord(string s) {
        int len = 0, prevlen = 0;
        for (auto &ch : s) {
            if (ch == ' ') {
                if (len != 0) prevlen = len;
                len = 0;
            } else {
                ++len;
            }
        }
        return len ? len : prevlen;
    }
};
