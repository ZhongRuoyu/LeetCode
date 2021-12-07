// Solved 2021-12-07
// Runtime: 24 ms (98.80%)
// Memory Usage: 27.5 MB (61.96%)

class Solution {
   public:
    int search(vector<int> &nums, int target) {
        if (nums.front() == target) {
            return 0;
        }
        int start = 0;
        int end = nums.size();
        while (start + 1 < end) {
            int mid = (start + end) / 2;
            if (nums[mid] < target) {
                start = mid;
            } else if (nums[mid] > target) {
                end = mid;
            } else {
                return mid;
            }
        }
        return -1;
    }
};
