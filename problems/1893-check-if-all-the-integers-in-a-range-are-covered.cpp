// Solved 2022-01-26
// Runtime: 4 ms (79.49%)
// Memory Usage: 8.8 MB (87.55%)

class Solution {
   public:
    bool isCovered(vector<vector<int>> &ranges, int left, int right) {
        vector<int> line(52);
        for (auto &range : ranges) {
            ++line[range[0]];
            --line[range[1] + 1];
        }
        {
            int overlap = 0;
            for (size_t i = 0; i <= right; ++i) {
                overlap += line[i];
                if (i >= left && overlap <= 0) {
                    return false;
                }
            }
        }
        return true;
    }
};
