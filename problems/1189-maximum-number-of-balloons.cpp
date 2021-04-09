// Solved 2021-04-09 11:34
// Runtime: 4 ms (80.85%)
// Memory Usage: 6.5 MB (67.36%)

class Solution {
   public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> lookup[2]{
            {{'a', 0}, {'b', 0}, {'n', 0}},
            {{'l', 0}, {'o', 0}}};
        for (auto &ch : text) {
            if (ch == 'a' || ch == 'b' || ch == 'n') {
                ++lookup[0][ch];
            } else if (ch == 'l' || ch == 'o') {
                ++lookup[1][ch];
            }
        }
        int res = 0, i;
        while (true) {
            for (i = 0; i != 2; ++i) {
                for (auto &pair : lookup[i]) {
                    pair.second -= i + 1;
                    if (pair.second < 0) return res;
                }
            }
            ++res;
        }
    }
};
