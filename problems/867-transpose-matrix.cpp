// Solved 2021-05-10 08:00
// Runtime: 8 ms (95.21%)
// Memory Usage: 10.4 MB (99.73%)

class Solution {
   public:
    vector<vector<int>> transpose(vector<vector<int>> &A) {
        vector<vector<int>> AT(A[0].size(), vector<int>(A.size()));
        for (int i = 0; i != AT.size(); ++i) {
            for (int j = 0; j != AT[0].size(); ++j) {
                AT[i][j] = A[j][i];
            }
        }
        return AT;
    }
};
