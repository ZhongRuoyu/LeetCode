// Solved 2022-02-02
// Runtime: 11 ms (88.66%)
// Memory Usage: 16.1 MB (91.24%)

class Solution {
   public:
    vector<int> buildArray(vector<int> &nums) {
        int n = nums.size();
        for (size_t i = 0; i != n; ++i) {
            nums[i] += (nums[nums[i]] % n) * n;
        }
        for_each(nums.begin(), nums.end(), [=](int &x) { x /= n; });
        return nums;
    }
};
