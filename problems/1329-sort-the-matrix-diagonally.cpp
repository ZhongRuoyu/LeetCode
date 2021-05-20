// Solved 2021-05-20 10:14
// Runtime: 8 ms (91.56%)
// Memory Usage: 9.2 MB (69.03%)

class Solution {
   public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> diagonals;
        for (int i = 0; i != mat.size(); ++i) {
            for (int j = 0; j != mat[0].size(); ++j) {
                diagonals[i - j].emplace(mat[i][j]);
            }
        }
        for (int i = 0; i != mat.size(); ++i) {
            for (int j = 0; j != mat[0].size(); ++j) {
                mat[i][j] = diagonals[i - j].top();
                diagonals[i - j].pop();
            }
        }
        return mat;
    }
};
