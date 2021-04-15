// Solved 2021-04-15 09:45
// Runtime: 0 ms (100.00%)
// Memory Usage: 6.9 MB (90.83%)

class Solution {
   public:
    void rotate(vector<vector<int>> &matrix) {
        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i != matrix.size(); ++i) {
            for (int j = i + 1; j != matrix.size(); ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
