// Solved 2021-06-01 08:42
// Runtime: 0 ms (100.00%)
// Memory Usage: 7.7 MB (99.13%)

class Solution {
   public:
    int sumOfUnique(vector<int> &nums) {
        array<int, 100> c{};
        for (auto &i : nums) ++c[i - 1];
        return accumulate(nums.begin(), nums.end(), 0, [&](int a, int b) { return c[b - 1] == 1 ? a + b : a; });
    }
};
