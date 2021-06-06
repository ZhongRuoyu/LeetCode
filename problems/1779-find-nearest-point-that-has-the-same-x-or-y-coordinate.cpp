// Solved 2021-06-07 00:06
// Runtime: 156 ms (65.96%)
// Memory Usage: 59.2 MB (95.50%)

class Solution {
   public:
    int nearestValidPoint(int x, int y, vector<vector<int>> &points) {
        int res = -1, nearest = INT_MAX;
        for (int i = 0; i != points.size(); ++i) {
            if (points[i][0] == x || points[i][1] == y) {
                if (abs(x - points[i][0]) + abs(y - points[i][1]) < nearest) {
                    nearest = abs(x - points[i][0]) + abs(y - points[i][1]);
                    res = i;
                }
            }
        }
        return res;
    }
};
