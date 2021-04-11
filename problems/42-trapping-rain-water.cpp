// Solved 2021-04-11 17:01
// Runtime: 0 ms (100.00%)
// Memory Usage: 14.1 MB (92.24%)

class Solution {
   public:
    int trap(vector<int> &height) {
        if (height.empty()) return 0;
        int l = 0, r = height.size() - 1,
            lmax = height[l], rmax = height[r],
            res = 0;
        while (l < r) {
            // the amount of water trapped at each index
            // depends only on its height and min(lmax, rmax)
            if (height[l] < height[r]) {
                // here we use the fact that height[r] <= rmax
                // height[l] < height[r] <= rmax
                if (height[l] >= lmax) {
                    // update lmax; no water will be trapped here
                    // as height[l] >= lmax >= min(lmax, rmax)
                    lmax = height[l];
                } else {
                    // l would have stopped at lmax if lmax > rmax
                    res += lmax - height[l];
                }
                ++l;
            } else {
                // height[r] <= height[l] <= lmax
                if (height[r] >= rmax) {
                    // height[r] >= rmax >= min(lmax, rmax)
                    rmax = height[r];
                } else {
                    // r would have stopped at rmax if rmax > lmax
                    res += rmax - height[r];
                }
                --r;
            }
        }
        return res;
    }
};
