// Solved 2022-01-19
// Runtime: 4 ms (76.93%)
// Memory Usage: 12.3 MB (69.74%)

class Solution {
   public:
    int findMiddleIndex(vector<int> &nums) {
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

// See also: Problem 724 (Find Pivot Index)
