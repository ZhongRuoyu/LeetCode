// Solved 2021-02-12 15:50
// Runtime: 4 ms (92.94%)
// Memory Usage: 6 MB (87.26%)

class Solution {
   public:
    int romanToInt(string s) {
        static const unordered_map<char, int> lookup{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};
        char prev = '\0';
        int res = 0;
        for (int i = 0; i != s.size(); ++i) {
            if (i && lookup.at(s[i - 1]) < lookup.at(s[i])) {
                res -= 2 * lookup.at(s[i - 1]);
            }
            res += lookup.at(s[i]);
        }
        return res;
    }
};

// See also: Problem 12 (Integer to Roman)

// Happy New Year
