// Solved 2021-05-11 10:49
// Runtime: 8 ms (96.77%)
// Memory Usage: 10.7 MB (94.96%)

class Solution {
   public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c) {
        const int m = nums.size(), n = nums[0].size();
        if (m * n != r * c) return nums;
        if (m == r && n == c) return nums;
        vector<vector<int>> res(r, vector<int>(c));
        int i = 0, j = 0, inums = 0, jnums = 0;
        while (i != r) {
            if (j == c) {
                ++i;
                j = 0;
                continue;
            }
            if (jnums == n) {
                ++inums;
                jnums = 0;
                continue;
            }
            res[i][j] = nums[inums][jnums];
            ++j, ++jnums;
        }
        return res;
    }
};
