// Solved 2021-12-04
// Runtime: 8 ms (99.74%)
// Memory Usage: 19.5 MB (99.45%)

class Solution {
   public:
    int majorityElement(vector<int> &nums) {
        int count = 0;
        int candidate = 0;
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }
        return candidate;
    }
};
