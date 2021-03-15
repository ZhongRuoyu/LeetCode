// Solved 2021-03-15 17:52
// Runtime: 36 ms (96.77%)
// Memory Usage: 15.8 MB (97.62%)

class Solution {
   public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {
        int res = 0;
        sort(boxTypes.begin(), boxTypes.end(),
             [](vector<int> &a, vector<int> &b) {
                 return a[1] > b[1];
             });
        for (auto &i : boxTypes) {
            if (truckSize < i[0]) {
                res += truckSize * i[1];
                break;
            }
            res += i[0] * i[1];
            truckSize -= i[0];
        }
        return res;
    }
};
