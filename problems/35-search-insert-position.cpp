// Solved 2021-03-29 08:19
// Runtime: 0 ms (100.00%)
// Memory Usage: 9.6 MB (85.54%)

class Solution {
   public:
    int searchInsert(vector<int> &nums, int target) {
        int res = 0;
        while (res != nums.size() && target > nums[res]) ++res;
        return res;
    }
};
