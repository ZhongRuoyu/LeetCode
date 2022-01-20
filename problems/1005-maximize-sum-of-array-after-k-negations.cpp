// Solved 2022-01-20
// Runtime: 4 ms (85.41%)
// Memory Usage: 9 MB (60.72%)

class Solution {
   public:
    int largestSumAfterKNegations(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        int min = numeric_limits<int>::max();
        for (size_t i = 0; i != nums.size(); ++i) {
            if (k > 0 && nums[i] <= 0) {
                nums[i] = -nums[i];
                --k;
            }
            sum += nums[i];
            min = std::min(min, nums[i]);
        }
        if (k % 2 == 1) {
            sum -= 2 * min;
        }
        return sum;
    }
};
