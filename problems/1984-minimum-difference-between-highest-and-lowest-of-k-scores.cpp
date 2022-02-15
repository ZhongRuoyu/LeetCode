// Solved 2022-02-15
// Runtime: 19 ms (65.82%)
// Memory Usage: 13.5 MB (94.94%)

class Solution {
   public:
    int minimumDifference(vector<int> &nums, int k) {
        sort(begin(nums), end(nums));
        int result = numeric_limits<int>::max();
        for (size_t i = k - 1; i < nums.size(); ++i) {
            result = min(result, nums[i] - nums[i - k + 1]);
        }
        return result;
    }
};
