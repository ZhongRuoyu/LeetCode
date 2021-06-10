// Solved 2021-06-11
// Runtime: 0 ms (100.00%)
// Memory Usage: 8.4 MB (80.39%)

class Solution {
   public:
    int maxAscendingSum(vector<int> &nums) {
        int sum = nums.front(), max_sum = 0;
        for (int i = 1; i != nums.size(); ++i) {
            if (nums[i - 1] < nums[i]) {
                sum += nums[i];
            } else {
                max_sum = max(max_sum, sum);
                sum = nums[i];
            }
        }
        return max(max_sum, sum);
    }
};
