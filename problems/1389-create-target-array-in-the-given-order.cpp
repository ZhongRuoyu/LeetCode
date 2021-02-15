// Solved 2021-02-15 10:43
// Runtime: 0 ms (100.00%)
// Memory Usage: 8.3 MB (95.70%)

class Solution {
   public:
    vector<int> createTargetArray(vector<int> &nums, vector<int> &index) {
        vector<int> res;
        for (int i = 0; i != nums.size(); ++i) {
            res.insert(res.begin() + index[i], nums[i]);
        }
        return res;
    }
};
