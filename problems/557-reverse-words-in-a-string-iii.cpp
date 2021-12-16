// Solved 2021-12-10
// Runtime: 8 ms (99.11%)
// Memory Usage: 9.5 MB (99.37%)

class Solution {
   public:
    string reverseWords(string s) {
        auto prev = begin(s);
        for (auto it = begin(s); it != end(s); ++it) {
            if (*it == ' ') {
                reverse(prev, it);
                prev = it + 1;
            }
        }
        reverse(prev, end(s));
        return s;
    }
};
