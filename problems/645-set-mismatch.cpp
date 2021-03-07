// Solved 2021-03-07 13:47
// Runtime: 16 ms (99.89%)
// Memory Usage: 21.4 MB (89.93%)

class Solution {
   public:
    vector<int> findErrorNums(vector<int> &nums) {
        int x = 0, x1 = 0, x2 = 0;
        for (int i = 0; i != nums.size(); ++i) x ^= nums[i] ^ (i + 1);
        // x becomes ans[0] ^ ans[1]
        x &= -x;  // get least significant set bit
        for (int i = 0; i != nums.size(); ++i) {
            (nums[i] & x) ? x1 ^= nums[i] : x2 ^= nums[i];
            ((i + 1) & x) ? x1 ^= i + 1 : x2 ^= i + 1;
        }  // group nums by least significant set bit
        for (auto &i : nums) {
            if (i == x1) return {x1, x2};  // x1 is in nums
        }
        return {x2, x1};  // x2 is in nums
    }
};
