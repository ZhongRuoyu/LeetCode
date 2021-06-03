// Solved 2021-06-03 09:32
// Runtime: 0 ms (100.00%)
// Memory Usage: 8.3 MB (94.86%)

class Solution {
   public:
    bool check(vector<int> &nums) {
        int start = -1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] > nums[i]) {
                if (start != -1) return false;
                start = i;
            }
        }
        return start == -1 || nums.back() <= nums.front();
    }
};
