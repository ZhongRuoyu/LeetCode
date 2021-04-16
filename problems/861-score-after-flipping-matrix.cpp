// Solved 2021-04-16 09:20
// Runtime: 0 ms (100.00%)
// Memory Usage: 8 MB (99.53%)

class Solution {
   public:
    int matrixScore(vector<vector<int>> &A) {
        const int m = A.size(), n = A[0].size();
        int score = m * (1 << (n - 1)),
            i, j,
            colCount;  // counts set bit while traversing columns
        for (j = 1; j < n; ++j) {
            colCount = 0;
            for (i = 0; i < m; ++i) {
                colCount += (A[i][0] == A[i][j]);
            }
            score += max(colCount, m - colCount) * (1 << (n - j - 1));
        }
        return score;
    }
};
