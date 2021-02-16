// Solved 2021-02-16 09:48
// Runtime: 4 ms (99.52%)
// Memory Usage: 6.1 MB (84.13%)

class Solution {
   public:
    vector<int> closestDivisors(int num) {
        for (int x = sqrt(num + 2); x; --x) {
            if ((num + 1) % x == 0) return {x, (num + 1) / x};
            if ((num + 2) % x == 0) return {x, (num + 2) / x};
        }
        return {};
    }
};
