// Solved 2021-01-15 10:40
// Runtime: 16 ms (99.97%)
// Memory Usage: 23.9 MB (99.49%)

class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int i, p = 1;
        vector<int> ans(nums.size());
        ans[0] = 1;
        for (int i = 1; i != nums.size(); ++i) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        for (i = nums.size() - 1; i >= 0; --i) {
            ans[i] *= p;
            p *= nums[i];
        }
        return ans;
    }
};
