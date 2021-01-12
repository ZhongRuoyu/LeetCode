// Solved 2021-01-12 11:30
// Runtime: 44 ms (96.94%)
// Memory Usage: 22.6 MB (77.41%)

class Solution {
   public:
    bool validMountainArray(vector<int>& arr) {
        int i = 0;
        while (i + 1 < arr.size() && arr[i] < arr[i + 1]) ++i;
        if (i == 0 || i == arr.size() - 1) return false;
        while (i + 1 < arr.size() && arr[i] > arr[i + 1]) ++i;
        return (i == arr.size() - 1);
    }
};

// Bon voyage
