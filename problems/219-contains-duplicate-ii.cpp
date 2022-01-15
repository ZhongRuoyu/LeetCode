// Solved 2022-01-15
// Runtime: 168 ms (66.90%)
// Memory Usage: 72.3 MB (90.07%)

class Solution {
   public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_set<int> window;
        for (size_t i = 0; i != nums.size(); ++i) {
            if (i > k) {
                window.erase(nums[i - k - 1]);
            }
            if (window.find(nums[i]) != window.end()) {
                return true;
            }
            window.insert(nums[i]);
        }
        return false;
    }
};

/*

An alternative solution using unordered_map:

class Solution {
   public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_map<int, int> last_occurrence;
        for (size_t i = 0; i != nums.size(); ++i) {
            if (last_occurrence.count(nums[i]) != 0 &&
                i - last_occurrence[nums[i]] <= k) {
                return true;
            }
            last_occurrence[nums[i]] = i;
        }
        return false;
    }
};

*/
