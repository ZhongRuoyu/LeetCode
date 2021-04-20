// Solved 2021-04-20 23:27
// Runtime: 0 ms (100.00%)
// Memory Usage: 8.2 MB (93.79%)

class Solution {
   public:
    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2) {
        const int left = max(rec1[0], rec2[0]),
                  bottom = max(rec1[1], rec2[1]),
                  right = min(rec1[2], rec2[2]),
                  top = min(rec1[3], rec2[3]);
        return (left < right && bottom < top);
    }
};
