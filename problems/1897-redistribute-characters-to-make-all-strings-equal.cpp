// Solved 2022-01-27
// Runtime: 12 ms (94.30%)
// Memory Usage: 11.6 MB (66.03%)

class Solution {
   public:
    bool makeEqual(vector<string> &words) {
        unsigned count[26] = {};
        for (string &word : words) {
            for (char ch : word) {
                ++count[ch - 'a'];
            }
        }
        return all_of(begin(count), end(count),
                      [&](int c) { return c % words.size() == 0; });
    }
};
