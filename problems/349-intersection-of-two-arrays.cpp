// Solved 2021-01-17 11:31
// Runtime: 4 ms (99.08%)
// Memory Usage: 10.3 MB (97.79%)

class Solution {
   public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> temp(nums1.begin(), nums1.end());
        vector<int> res;
        for (auto& num : nums2) {
            if (temp.count(num)) {
                res.push_back(num);
                temp.erase(num);
            }
        }
        return res;
    }
};
