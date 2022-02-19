// Solved 2022-02-19
// Runtime: 4 ms (78.53%)
// Memory Usage: 8.3 MB (80.80%)

class Solution {
   public:
    int maximumDifference(vector<int> &nums) {
        int difference = 0;
        int i = 0;
        for (size_t j = 1; j < nums.size(); ++j) {
            if (nums[j] < nums[i]) {
                i = j;
            } else {
                difference = max(difference, nums[j] - nums[i]);
            }
        }
        return difference > 0 ? difference : -1;
    }
};

// See also: Problem 121 (Best Time to Buy and Sell Stock)
