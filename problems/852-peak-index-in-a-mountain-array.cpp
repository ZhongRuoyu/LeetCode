// Solved 2021-02-18 08:00
// Runtime: 8 ms (96.54%)
// Memory Usage: 11.3 MB (99.45%)

class Solution {
   public:
    int peakIndexInMountainArray(vector<int> &arr) {
        int ans = 0;
        while (ans + 1 < arr.size() && arr[ans] < arr[ans + 1]) ++ans;
        return ans;
    }
};
