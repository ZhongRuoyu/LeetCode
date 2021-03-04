// Solved 2021-03-04 11:17
// Runtime: 4 ms (99.80%)
// Memory Usage: 13.8 MB (96.45%)

class Solution {
   public:
    vector<bool> prefixesDivBy5(vector<int> &A) {
        vector<bool> res;
        unsigned x = 0;
        for (auto &i : A) {
            x = ((x << 1) + i) % 5;
            res.emplace_back(x == 0);
        }
        return res;
    }
};
