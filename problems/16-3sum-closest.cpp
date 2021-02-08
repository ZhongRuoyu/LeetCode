// Solved 2021-02-08 11:08
// Runtime: 4 ms (99.31%)
// Memory Usage: 9.8 MB (95.49%)

class Solution {
   public:
    int threeSumClosest(vector<int> &nums, int target) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2], i = 0;
        while (i < n - 2) {
            int a = nums[i],
                l = i + 1, r = n - 1;
            while (l < r) {
                int b = nums[l], c = nums[r], sum = a + b + c;
                if (sum == target) return sum;
                if (abs(target - sum) < abs(target - closest)) {
                    closest = sum;
                }
                if (sum <= target) {
                    while (l < r && nums[l] == b) ++l;
                }
                if (sum >= target) {
                    while (l < r && nums[r] == c) --r;
                }
            }
            while (i < n - 2 && nums[i] == a) ++i;
        }
        return closest;
    }
};

// See also: Problem 1 (Two Sum), Problem 15 (3Sum), Problem 18 (4Sum)
