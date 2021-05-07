// Solved 2021-05-07 08:14
// Runtime: 0 ms (100.00%)
// Memory Usage: 7.2 MB (89.09%)

class Solution {
   public:
    int numIdenticalPairs(vector<int> &nums) {
        int res = 0;
        unordered_map<int, int> count;
        for (auto a : nums) {
            res += count[a]++;
        }
        return res;
    }
};
