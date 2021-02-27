// Solved 2021-02-27 14:45
// Runtime: 4 ms (96.85%)
// Memory Usage: 7.7 MB (91.44%)

class Solution {
   public:
    int maximumWealth(vector<vector<int>> &accounts) {
        int ans = 0;
        for (auto &account : accounts) {
            ans = max(ans, accumulate(account.begin(), account.end(), 0));
        }
        return ans;
    }
};
