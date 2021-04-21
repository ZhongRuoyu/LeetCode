// Solved 2021-04-21 19:39
// Runtime: 4 ms (88.22%)
// Memory Usage: 5.7 MB (96.43%)

class Solution {
   public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        const int areaA = (C - A) * (D - B),
                  areaB = (G - E) * (H - F),
                  left = max(A, E),
                  bottom = max(B, F),
                  right = min(C, G),
                  top = min(D, H);
        if (left >= right || bottom >= top) return areaA + areaB;
        return -(right - left) * (top - bottom) + areaA + areaB;
    }
};
