// Solved 2021-03-11 08:01
// Runtime: 192 ms (93.95%)
// Memory Usage: 67.7 MB (94.74%)

class Solution {
   public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n) {
        vector<int> ans(n, 0);
        for (auto &i : bookings) {
            ans[i[0] - 1] += i[2];
            if (i[1] < n) ans[i[1]] -= i[2];
        }
        for (int i = 1; i < ans.size(); ++i) {
            ans[i] += ans[i - 1];
        }
        return ans;
    }
};
