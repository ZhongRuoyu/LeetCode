// Solved 2022-02-10
// Runtime: 3 ms (90.39%)
// Memory Usage: 13.8 MB (94.91%)

class Solution {
   public:
    bool isPrefixString(string s, vector<string> &words) {
        for (size_t i = 0, pos = 0; i != words.size(); ++i) {
            string substr = s.substr(pos, words[i].length());
            if (substr != words[i]) {
                return false;
            }
            pos += words[i].length();
            if (pos == s.size()) {
                return true;
            }
            if (pos > s.size()) {
                return false;
            }
        }
        return false;
    }
};
