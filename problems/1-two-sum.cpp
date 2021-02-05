// Solved 2021-02-05 10:01
// Runtime: 4 ms (97.95%)
// Memory Usage: 8.9 MB (91.57%)

class Solution {
   public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> lookup;
        for (int i = 0; i != nums.size(); ++i) {
            auto x = lookup.find(target - nums[i]);
            if (x != lookup.end()) return {i, x->second};
            lookup.insert({nums[i], i});
        }
        return {};
    }
};

// See also: Problem 15 (3Sum), Problem 16 (3Sum Closest), Problem 18 (4Sum)

// Happy birthday
