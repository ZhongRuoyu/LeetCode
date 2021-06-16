// Solved 2021-06-16
// Runtime: 4 ms (93.50%)
// Memory Usage: 9.5 MB (96.52%)

class Solution {
   public:
    int getMinDistance(vector<int> &nums, int target, int start) {
        int res = INT_MAX;
        for (int i = 0; i != nums.size() && abs(start - i) < res; ++i) {
            if (nums[i] == target) res = abs(start - i);
        }
        return res;
    }
};
