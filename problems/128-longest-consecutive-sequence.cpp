// Solved 2022-07-13
// Runtime: 164 ms (74.36%)
// Memory Usage: 45.6 MB (73.00%)

class Solution {
   public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> elements(nums.cbegin(), nums.cend());
        int result = 0;
        for (const auto num : elements) {
            if (elements.find(num - 1) == elements.end()) {
                int current = num;
                int streak = 1;
                while (elements.find(current + 1) != elements.end()) {
                    ++current;
                    ++streak;
                }
                result = max(result, streak);
            }
        }
        return result;
    }
};
