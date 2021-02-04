// Solved 2021-02-04 10:19
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.8 MB (98.96%)

class Solution {
   public:
    bool isNumber(string s) {
        if (s.empty()) return false;
        int i = 0;

        // sign
        if (s[i] == '+' || s[i] == '-') ++i;
        if (i == s.size()) return false;
        if (s[i] == '.' && (i + 1 == s.size() || !isdigit(s[i + 1]))) return false;
        if (s[i] == 'e' || s[i] == 'E') return false;

        // decimal part
        while (i != s.size() && isdigit(s[i])) ++i;
        if (i == s.size()) return true;

        // fractional part
        if (s[i] == '.') {
            ++i;
            if (i == s.size()) return true;
            while (i != s.size() && isdigit(s[i])) ++i;
            if (i == s.size()) return true;
        }

        // exponent part
        if (s[i] == 'e' || s[i] == 'E') {
            ++i;
            if (s[i] == '+' || s[i] == '-') ++i;
            if (i == s.size() || !isdigit(s[i])) return false;
            while (i != s.size() && isdigit(s[i])) ++i;
            if (i == s.size()) return true;
        }

        return false;
    }
};

/* 

Another approach using RegEx:

class Solution {
   public:
    bool isNumber(string s) {
        static const regex match{"^[+-]?(?:\\d*\\.\\d+|\\d+\\.\\d*|\\d+)[Ee][+-]?\\d+$|^[+-]?(?:\\d*\\.\\d+|\\d+\\.\\d*|\\d+)$"};
        return regex_match(s, match);
    }
};

*/
