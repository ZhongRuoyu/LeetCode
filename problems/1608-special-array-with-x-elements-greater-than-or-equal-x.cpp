// Solved 2021-05-06 21:35
// Runtime: 0 ms (100.00%)
// Memory Usage: 8.3 MB (85.38%)

class Solution {
   public:
    int specialArray(vector<int> &nums) {
        int x;
        sort(nums.begin(), nums.end(),
             [](int &a, int &b) {
                 return (a > b);
             });
        for (x = 1; x != nums.size(); ++x) {
            if (nums[x - 1] >= x && x > nums[x]) return x;
        }
        return (nums[x - 1] >= x) ? x : -1;
    }
};
