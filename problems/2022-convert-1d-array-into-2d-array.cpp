// Solved 2022-02-05
// Runtime: 104 ms (92.43%)
// Memory Usage: 85.4 MB (82.61%)

class Solution {
   public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n) {
        if (original.size() != m * n) {
            return {};
        }
        vector<vector<int>> result(m, vector<int>(n));
        for (size_t i = 0; i != original.size(); ++i) {
            int row = i / n;
            int col = i % n;
            result[row][col] = original[i];
        }
        return result;
    }
};

// class Solution {
//    public:
//     vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
//     {
//         vector<vector<int>> result;
//         if (original.size() == m * n) {
//             for (auto i : original) {
//                 if (result.empty() || result.back().size() == n) {
//                     result.emplace_back();
//                 }
//                 result.back().push_back(i);
//             }
//         }
//         return result;
//     }
// };

// Happy birthday
