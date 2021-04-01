// Solved 2021-04-01 10:26
// Runtime: 4 ms (95.35%)
// Memory Usage: 10.3 MB (28.60%)

class Solution {
   public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
        unordered_map<int, int> lookup;
        vector<int> ans(nums.begin(), nums.end());
        sort(ans.begin(), ans.end());
        // ans is used to temporarily store the sorted array.
        // The index (0-based) of the first occurrence of a number
        // is exactly the number of numbers smaller than it.
        for (int i = 0; i != nums.size(); ++i) {
            if (lookup.find(ans[i]) == lookup.end()) {
                lookup.insert({ans[i], i});
            }
        }
        // now ans is used to store the answer
        for (int i = 0; i != nums.size(); ++i) {
            ans[i] = lookup[nums[i]];
        }
        return ans;
    }
};
