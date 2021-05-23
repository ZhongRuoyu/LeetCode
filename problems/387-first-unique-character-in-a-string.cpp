// Solved 2021-05-23 12:29
// Runtime: 44 ms (44.73%)
// Memory Usage: 10.6 MB (53.09%)

class Solution {
   public:
    int firstUniqChar(string s) {
        if (s.empty()) return -1;
        unordered_map<char, int> lookup;
        for (int i = 0; i != s.size(); ++i) {
            if (lookup.find(s[i]) == lookup.end()) {
                lookup.insert({s[i], i});
            } else {
                lookup[s[i]] = INT_MAX;
            }
        }
        const int ans = min_element(
                            lookup.begin(), lookup.end(),
                            [](const pair<char, int> &x, const pair<char, int> &y) {
                                return (x.second < y.second);
                            })
                            ->second;
        return (ans == INT_MAX) ? -1 : ans;
    }
};

// It would be faster if an array of char is used.
// unordered_map is used instead for flexibility.
