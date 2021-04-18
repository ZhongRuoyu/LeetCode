// Solved 2021-04-18 14:18
// Runtime: 44 ms (90.37%)
// Memory Usage: 21.9 MB (74.09%)

class Solution {
   public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for (int j = 2; j <= n; ++j) {
            for (int i = 1; i != j; ++i) {
                if (gcd(i, j) == 1) {
                    ans.emplace_back(to_string(i) + "/" + to_string(j));
                }
            }
        }
        return ans;
    }
};
