// Solved 2021-03-27 13:11
// Runtime: 0 ms (100.00%)
// Memory Usage: 8.7 MB (87.93%)

class Solution {
   public:
    int removeElement(vector<int> &nums, int val) {
        int l = -1, r = -1;
        while (r != nums.size()) {
            while (++r != nums.size() && nums[r] == val) continue;
            if (++l != r && r != nums.size()) nums[l] = nums[r];
        }
        return l;
    }
};

// See also: Problem 26 (Remove Duplicates from Sorted Array)
