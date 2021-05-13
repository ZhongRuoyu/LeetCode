// Solved 2021-05-13 11:01
// Runtime: 4 ms (92.65%)
// Memory Usage: 8.5 MB (87.92%)

class Solution {
   public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<vector<int>> res;
        vector<bool> visited(nums.size());
        vector<int> curr;
        sort(nums.begin(), nums.end());
        backtrack(nums, res, visited, curr, 0);
        return res;
    }

   private:
    void backtrack(
        vector<int> &nums, vector<vector<int>> &res, vector<bool> &visited,
        vector<int> &curr, int depth) {
        if (depth == nums.size()) {
            res.emplace_back(curr);
        } else {
            for (int i = 0; i != nums.size(); ++i) {
                if (visited[i] ||
                    (i != 0 && nums[i - 1] == nums[i] && !visited[i - 1])) {
                    // (i != 0 && nums[i - 1] == nums[i] && !visited[i - 1])
                    // ensures that we firstly visit the first in consecutive
                    // identical elements.
                    continue;
                }
                visited[i] = true;
                curr.emplace_back(nums[i]);
                backtrack(nums, res, visited, curr, depth + 1);
                curr.pop_back();
                visited[i] = false;
            }
        }
    }
};

// See also: Problem 46 (Permutations)
