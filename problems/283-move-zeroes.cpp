// Solved 2021-01-22 08:19
// Runtime: 0 ms (100.00%)
// Memory Usage: 8.8 MB (96.76%)

class Solution {
   public:
    void moveZeroes(vector<int> &nums) {
        int l = 0, r = 0;
        while (r < nums.size()) {
            if (nums[r]) {
                swap(nums[l], nums[r]);
                ++l;
            }
            ++r;
        }
    }
};
