// Solved 2022-01-18
// Runtime: 20 ms (88.70%)
// Memory Usage: 31 MB (63.94%)

class Solution {
   public:
    int pivotIndex(vector<int> &nums) {
        int postfix_sum = accumulate(begin(nums), end(nums), 0);
        int prefix_sum = 0;
        for (size_t i = 0; i != nums.size(); ++i) {
            postfix_sum -= nums[i];
            if (prefix_sum == postfix_sum) {
                return i;
            }
            prefix_sum += nums[i];
        }
        return -1;
    }
};

// See also: Problem 1991 (Find the Middle Index in Array)
