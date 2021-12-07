// Solved 2021-12-07
// Runtime: 23 ms (79.47%)
// Memory Usage: 15.4 MB (92.94%)

class Solution {
   public:
    bool containsDuplicate(vector<int> &nums) {
        if (nums.size() <= 1) {
            return false;
        }
        sort(begin(nums), end(nums));
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] == nums[i]) {
                return true;
            }
        }
        return false;
    }
};

/*

A one-line solution:

class Solution {
   public:
    bool containsDuplicate(vector<int> &nums) {
        return nums.size() > set<int>(begin(nums), end(nums)).size();
    }
};

*/
