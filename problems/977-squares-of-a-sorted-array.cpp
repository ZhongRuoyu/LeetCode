// Solved 2021-12-08
// Runtime: 22 ms (92.77%)
// Memory Usage: 25.8 MB (95.46%)

class Solution {
   public:
    vector<int> sortedSquares(vector<int> &nums) {
        vector<int> result(nums.size());
        size_t p = result.size();
        size_t start = 0;
        size_t end = nums.size() - 1;
        while (end >= start) {
            int start2 = nums[start] * nums[start];
            int end2 = nums[end] * nums[end];
            if (start2 >= end2) {
                result[--p] = start2;
                ++start;
            } else {
                result[--p] = end2;
                --end;
            }
        }
        return result;
    }
};
