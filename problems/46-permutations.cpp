// Solved 2021-05-12 09:06
// Runtime: 0 ms (100.00%)
// Memory Usage: 7.6 MB (84.15%)

class Solution {
   public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> res;
        backtrack(nums, res, 0);
        return res;
    }

   private:
    void backtrack(vector<int> &nums, vector<vector<int>> &res, int begin) {
        if (begin == nums.size()) {
            res.emplace_back(nums);
        } else {
            for (int i = begin; i != nums.size(); ++i) {
                swap(nums[begin], nums[i]);
                backtrack(nums, res, begin + 1);
                swap(nums[begin], nums[i]);
            }
        }
    }
};

/* 

Another approach which does not swap numbers, but instead keeps a copy of our
backtracking progress. Result is in dictionary order if nums is so.

This approach is used in Problem 47.

class Solution {
   public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> res;
        vector<bool> visited(nums.size());
        vector<int> curr;
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
                if (visited[i]) continue;
                visited[i] = true;
                curr.emplace_back(nums[i]);
                backtrack(nums, res, visited, curr, depth + 1);
                curr.pop_back();
                visited[i] = false;
            }
        }
    }
};

*/

// See also: Problem 47 (Permutations II)
