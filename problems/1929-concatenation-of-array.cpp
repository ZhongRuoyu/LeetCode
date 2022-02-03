// Solved 2022-02-03
// Runtime: 8 ms (85.11%)
// Memory Usage: 12.4 MB (95.32%)

class Solution {
   public:
    vector<int> getConcatenation(vector<int> &nums) {
        vector<int> result(nums.size() * 2);
        copy(nums.begin(), nums.end(), result.begin());
        copy(nums.begin(), nums.end(), result.begin() + nums.size());
        return result;
    }
};
