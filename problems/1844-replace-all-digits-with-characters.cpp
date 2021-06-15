// Solved 2021-06-15
// Runtime: 0 ms (100.00%)
// Memory Usage: 6 MB (68.22%)

class Solution {
   public:
    string replaceDigits(string s) {
        for (int i = 0; i < s.size(); i += 2) {
            s[i + 1] = s[i] + s[i + 1] - '0';
        }
        return s;
    }
};
