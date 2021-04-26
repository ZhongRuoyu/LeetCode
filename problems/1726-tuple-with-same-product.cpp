// Solved 2021-04-26 09:04
// Runtime: 432 ms (95.32%)
// Memory Usage: 81.6 MB (92.42%)

class Solution {
   public:
    int tupleSameProduct(vector<int> &nums) {
        int res = 0;
        unordered_map<int, int> lookup;  // counts product results
        for (int i = 0; i != nums.size(); ++i) {
            for (int j = i + 1; j != nums.size(); ++j) {
                res += 8 * lookup[nums[i] * nums[j]]++;  // each tuple has 8 permutations
            }
        }
        return res;
    }
};
