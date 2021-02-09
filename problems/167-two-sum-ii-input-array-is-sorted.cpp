// Solved 2021-02-09 08:22
// Runtime: 4 ms (95.28%)
// Memory Usage: 9.5 MB (94.71%)

class Solution {
   public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ans{0, (int)numbers.size() - 1};
        while (numbers[ans[0]] + numbers[ans[1]] != target) {
            if (numbers[ans[0]] + numbers[ans[1]] > target) {
                --ans[1];
            } else {
                ++ans[0];
            }
        }
        ++ans[0], ++ans[1];
        return ans;
    }
};

// See also: Problem 1 (Two Sum)
