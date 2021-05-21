// Solved 2021-05-21 23:59
// Runtime: 276 ms (58.13%)
// Memory Usage: 66.2 MB (94.90%)

class Solution {
   public:
    int maxWidthOfVerticalArea(vector<vector<int>> &points) {
        if (points.size() < 2) return 0;
        sort(points.begin(), points.end(),
             [](const vector<int> &x, const vector<int> &y) {
                 return (x[0] < y[0]);
             });
        int maxWidth = 0;
        for (int i = 1; i != points.size(); ++i) {
            maxWidth = max(maxWidth, points[i][0] - points[i - 1][0]);
        }
        return maxWidth;
    }
};
