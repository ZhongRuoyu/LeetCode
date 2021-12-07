// Solved 2021-12-07
// Runtime: 96 ms (90.58%)
// Memory Usage: 67.6 MB (91.24%)

class Solution {
   public:
    int maxSubArray(vector<int> &nums) {
        int sum = 0;
        int max = numeric_limits<int>::min();
        for (size_t i = 0; i != nums.size(); ++i) {
            sum += nums[i];
            max = std::max(max, sum);
            sum = std::max(sum, 0);
        }
        return max;
    }
};
