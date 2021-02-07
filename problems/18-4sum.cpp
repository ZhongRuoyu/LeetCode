// Solved 2021-02-07 11:38
// Runtime: 12 ms (95.01%)
// Memory Usage: 13.2 MB (69.25%)

class Solution {
   public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        return kSum(nums, target, 4, 0);
    }

   private:
    vector<vector<int>> kSum(vector<int> &nums, int target, int k, int start) {
        // kSum assumes that nums is sorted
        const int n = nums.size();
        if (k < 2 || start < 0 || start + k > n ||
            k * nums[start] > target || k * nums[n - 1] < target) {
            // invalid cases short-circuited
            return {};
        }
        vector<vector<int>> res;
        if (k == 2) {
            // base case
            int l = start, r = n - 1;
            while (l < r) {
                int a = nums[l], b = nums[r], sum = a + b;
                if (sum == target) res.push_back({a, b});
                if (sum <= target) {
                    while (l < r && nums[l] == a) ++l;
                }
                if (sum >= target) {
                    while (l < r && nums[r] == b) --r;
                }
            }
            return res;
        }
        // recursive cases
        int i = start;
        while (i <= n - k) {
            int a = nums[i];
            vector<vector<int>> curr{kSum(nums, target - a, k - 1, i + 1)};
            for (auto &v : curr) {
                v.emplace_back(a);
                // result not in order
                // to put result in order, use the following line instead:
                // v.insert(v.begin(), a);
            }
            res.insert(res.end(), curr.begin(), curr.end());
            while (i <= n - k && nums[i] == a) ++i;
        }
        return res;
    }
};

/* 

Another solution, similar to 3Sum (Problem 15).
Less smart and less neat, but also less memory-consuming.

class Solution {
   public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        const int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < n - 3) {
            int a = nums[i],
                j = i + 1;
            while (j < n - 2) {
                int b = nums[j],
                    l = j + 1, r = n - 1;
                while (l < r) {
                    int c = nums[l], d = nums[r], sum = a + b + c + d;
                    if (sum == target) res.push_back({a, b, c, d});
                    if (sum <= target) {
                        while (l < r && nums[l] == c) ++l;
                    }
                    if (sum >= target) {
                        while (l < r && nums[r] == d) --r;
                    }
                }
                while (j < n - 2 && nums[j] == b) ++j;
            }
            while (i < n - 3 && nums[i] == a) ++i;
        }
        return res;
    }
};

*/

// See also: Problem 1 (Two Sum), Problem 15 (3Sum), Problem 16 (3Sum Closest)
