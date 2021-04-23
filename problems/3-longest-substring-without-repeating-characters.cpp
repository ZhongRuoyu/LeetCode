// Solved 2021-04-23 16:50
// Runtime: 8 ms (84.65%)
// Memory Usage: 8.2 MB (66.80%)

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lookup;
        int i, start = 0, res = 0;
        for (i = 0; i != s.size(); ++i) {
            if (lookup.find(s[i]) != lookup.end() &&
                lookup[s[i]] >= start) {
                res = max(res, i - start);
                start = lookup[s[i]] + 1;
            }
            lookup[s[i]] = i;
        }
        res = max(res, i - start);
        return res;
    }
};
