// Solved 2021-12-16
// Runtime: 0 ms (100.00%)
// Memory Usage: 6.4 MB (91.58%)

class Solution {
   public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        result.emplace_back(1, 1);
        for (int i = 1; i < numRows; ++i) {
            vector<int> row(i + 1);
            row[0] = row[i] = 1;
            for (int j = 1; j < i; ++j) {
                row[j] = result[i - 1][j - 1] + result[i - 1][j];
            }
            result.push_back(row);
        }
        return result;
    }
};
