// Solved 2021-03-26 11:07
// Runtime: 8 ms (84.14%)
// Memory Usage: 13.6 MB (85.12%)

class Solution {
   public:
    int removeDuplicates(vector<int> &nums) {
        int l = 0, r = 0;
        while (r != nums.size()) {
            while (++r != nums.size() && nums[l] == nums[r]) continue;
            if (++l != r && r != nums.size()) nums[l] = nums[r];
        }
        return l;
    }
};

// See also: Problem 27 (Remove Element)
