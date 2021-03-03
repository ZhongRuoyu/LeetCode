// Solved 2021-03-03 18:29
// Runtime: 16 ms (99.70%)
// Memory Usage: 26.9 MB (84.29%)

class Solution {
   public:
    bool checkPossibility(vector<int> &nums) {
        bool modified = false;
        int prev = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (prev > nums[i]) {
                if (modified) return false;
                modified = true;
                if (i - 2 >= 0 && nums[i - 2] > nums[i]) continue;
            }
            prev = nums[i];
        }
        return true;
    }
};

/**
 * Note on how to modify the array:
 * 
 *                  i
 * nums 0  1  2  4  2  ... (don't care)
 *              [2]
 * In the case where nums[i - 2] <= nums[i],
 * we update nums[i - 1] to nums[i], i.e. update prev to nums[i].
 * 
 *                  i
 * nums 0  1  2  3  1  ... (don't care)
 *                 [3]
 * Conversely, in the case where nums[i - 2] > nums[i],
 * we update nums[i] to nums[i - 1], and hence leave prev unchanged.
 */
