// Solved 2021-04-27 10:09
// Runtime: 20 ms (94.51%)
// Memory Usage: 23.1 MB (85.02%)

class Solution {
   public:
    int numPairsDivisibleBy60(vector<int> &time) {
        int res = 0;
        vector<int> lookup(60);
        for (auto &t : time) {
            ++lookup[t % 60];
        }
        for (int i = 1; i != 30; ++i) {
            res += lookup[i] * lookup[60 - i];
        }
        while (lookup[0]--) res += lookup[0];
        while (lookup[30]--) res += lookup[30];
        return res;
    }
};
