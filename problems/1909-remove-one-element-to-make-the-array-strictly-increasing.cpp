// Solved 2022-01-29
// Runtime: 4 ms (83.12%)
// Memory Usage: 10 MB (62.97%)

class Solution {
   public:
    bool canBeIncreasing(vector<int> &nums) {
        int prev = nums[0];
        bool removed = false;
        for (size_t i = 1; i != nums.size(); ++i) {
            if (nums[i] <= prev) {
                if (removed) {
                    return false;
                }
                if (i == 1 || nums[i] > nums[i - 2]) {
                    prev = nums[i];
                }
                removed = true;
            } else {
                prev = nums[i];
            }
        }
        return true;
    }
};
