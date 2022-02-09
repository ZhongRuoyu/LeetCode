// Solved 2022-02-09
// Runtime: 130 ms (91.36%)
// Memory Usage: 41.1 MB (60.85%)

class Solution {
   public:
    string makeFancyString(string s) {
        string result;
        for (size_t i = 0; i != s.length(); ++i) {
            if (i >= 2 && s[i - 2] == s[i] && s[i - 1] == s[i]) {
                continue;
            }
            result.push_back(s[i]);
        }
        return result;
    }
};
