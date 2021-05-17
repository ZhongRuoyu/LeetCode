// Solved 2021-05-17 08:56
// Runtime: 0 ms (100.00%)
// Memory Usage: 8.1 MB (94.58%)

class Solution {
   public:
    bool containsPattern(vector<int> &arr, int m, int k) {
        if (m < 1 || k < 2) return true;
        int cnt = 0;
        for (int i = 0; i + m < arr.size(); ++i) {
            if (arr[i] == arr[i + m]) {
                ++cnt;
                if (cnt == (k - 1) * m) return true;
            } else {
                cnt = 0;
            }
        }
        return false;
    }
};
