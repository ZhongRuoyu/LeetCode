// Solved 2021-02-06 11:18
// Runtime: 72 ms (87.04%)
// Memory Usage: 19.9 MB (97.14%)

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        const int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < n - 2) {
            int a = nums[i],
                l = i + 1, r = n - 1;
            while (l < r) {
                int b = nums[l], c = nums[r], sum = a + b + c;
                if (sum == 0) res.push_back({a, b, c});
                if (sum <= 0) {
                    while (l < r && nums[l] == b) ++l;
                }
                if (sum >= 0) {
                    while (l < r && nums[r] == c) --r;
                }
            }
            while (i < n - 2 && nums[i] == a) ++i;
        }
        return res;
    }
};

// See also: Problem 1 (Two Sum), Problem 16 (3Sum Closest), Problem 18 (4Sum)
