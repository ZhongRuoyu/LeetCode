// Solved 2021-12-07
// Runtime: 4 ms (80.50%)
// Memory Usage: 9.7 MB (72.23%)

class Solution {
   public:
    int searchInsert(vector<int> &nums, int target) {
        int start = 0;
        int end = nums.size();
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < target) {
                start = mid + 1;
            } else if (nums[mid] > target) {
                end = mid;
            } else {
                return mid;
            }
        }
        return end;
    }
};

/*

The previous submission, which was not O(n log n):

// Solved 2021-03-29 08:19
// Runtime: 0 ms (100.00%)
// Memory Usage: 9.6 MB (85.54%)

class Solution {
   public:
    int searchInsert(vector<int> &nums, int target) {
        int res = 0;
        while (res != nums.size() && target > nums[res]) ++res;
        return res;
    }
};

*/
