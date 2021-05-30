// Solved 2021-05-30 09:35
// Runtime: 0 ms (100.00%)
// Memory Usage: 7.9 MB (94.03%)

class Solution {
   public:
    int largestAltitude(vector<int> &gain) {
        int curr = 0, max_alt = 0;
        for (auto &i : gain) {
            curr += i;
            max_alt = max(max_alt, curr);
        }
        return max_alt;
    }
};
