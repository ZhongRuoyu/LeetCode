// Solved 2021-05-15 09:04
// Runtime: 36 ms (86.28%)
// Memory Usage: 25.7 MB (99.49%)

class Solution {
   public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration) {
        int res = 0;
        for (int i = 0; i != timeSeries.size(); ++i) {
            res += min(duration,
                       (i + 1 != timeSeries.size()
                            ? timeSeries[i + 1] - timeSeries[i]
                            : duration));
        }
        return res;
    }
};
