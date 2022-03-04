// Solved 2021-05-14 18:39
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.8 MB (85.66%)

class Solution {
   public:
    int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0) return 0;
        if (m == 1 || n == 1) return 1;
        long long res = 1;
        // Formula:
        //   C((m - 1) + (n - 1), (m - 1))
        // = ((m - 1) + (n - 1))! / ((m - 1)! * (n - 1)!)
        // To prevent overflow:
        // - long long is used.
        // - Multiplication and division are performed simultaneously.
        for (int dividend = m, divisor = 1; dividend != m + n - 1; ++dividend, ++divisor) {
            res *= dividend;
            res /= divisor;
        }
        return res;
    }
};

/*

A less clever solution:

class Solution {
   public:
    int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0) return 0;
        if (m == 1 || n == 1) return 1;
        vector<vector<int>> grid(m, vector<int>(n, 1));
        for (int i = 1; i != m; ++i) {
            for (int j = 1; j != n; ++j) {
                grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
            }
        }
        return grid[m - 1][n - 1];
    }
};

*/
