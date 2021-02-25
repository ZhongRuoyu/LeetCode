// Solved 2021-02-25 09:48
// Runtime: 0 ms (100.00%)
// Memory Usage: 6.7 MB (95.13%)

class Solution {
   public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> res;
        int i = 0, j;
        while (i < nums.size()) {
            j = i + 1;
            while (j < nums.size() && nums[i] + (j - i) == nums[j]) ++j;
            if (j == i + 1) {
                res.push_back(to_string(nums[i]));
            } else {
                res.push_back(to_string(nums[i]) + "->" + to_string(nums[j - 1]));
            }
            i = j;
        }
        return res;
    }
};
