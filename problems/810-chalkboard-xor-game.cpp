// Solved 2021-05-27 08:57
// Runtime: 4 ms (98.86%)
// Memory Usage: 13 MB (89.77%)

class Solution {
   public:
    bool xorGame(vector<int> &nums) {
        return nums.size() % 2 == 0 || accumulate(nums.begin(), nums.end(), 0, bit_xor()) == 0;
    }
};
