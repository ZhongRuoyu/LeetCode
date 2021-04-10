// Solved 2021-04-10 13:30
// Runtime: 64 ms (49.27%)
// Memory Usage: 59 MB (34.73%)

class Solution {
   public:
    int maxArea(vector<int> &height) {
        int area = 0, l = 0, r = height.size() - 1;
        while (l < r) {
            area = max(area, (r - l) * min(height[l], height[r]));
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return area;
    }
};
