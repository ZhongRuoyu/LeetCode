// Solved 2021-04-25 09:16
// Runtime: 36 ms (90.45%)
// Memory Usage: 18.3 MB (95.96%)

class Solution {
   public:
    int countGoodRectangles(vector<vector<int>> &rectangles) {
        int maxSide = 0, maxCount = 0;
        for (auto &rect : rectangles) {
            int side = min(rect[0], rect[1]);
            if (side > maxSide) {
                maxSide = side;
                maxCount = 1;
            } else if (side == maxSide) {
                ++maxCount;
            }
        }
        return maxCount;
    }
};
