// Solved 2021-04-12 09:21
// Runtime: 4 ms (100.00%)
// Memory Usage: 14.2 MB (78.97%)

class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &x, const vector<int> &y) {
                 return (x[0] < y[0]);
             });
        vector<vector<int>> res;
        int begin, end;
        for (int i = 0; i != intervals.size(); ++i) {
            begin = intervals[i][0], end = intervals[i][1];
            while (i + 1 != intervals.size() && end >= intervals[i + 1][0]) {
                end = max(end, intervals[++i][1]);
            }
            res.push_back({begin, end});
        }
        return res;
    }
};
