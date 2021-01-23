// Solved 2021-01-23 10:46
// Runtime: 76 ms (99.21%)
// Memory Usage: 95.8 MB (99.40%)

class Solution {
   public:
    int islandPerimeter(vector<vector<int>> &grid) {
        static constexpr int x[4] = {1, 0, -1, 0};
        static constexpr int y[4] = {0, 1, 0, -1};
        const int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    int local = 0;
                    for (int k = 0; k < 4; ++k) {
                        int xc = i + x[k],
                            yc = j + y[k];
                        if (xc < 0 || xc >= m ||
                            yc < 0 || yc >= n ||
                            grid[xc][yc] == 0) {
                            ++local;
                        }
                    }
                    ans += local;
                }
            }
        }
        return ans;
    }
};
