// Solved 2021-02-10 08:38
// Runtime: 0 ms (100.00%)
// Memory Usage: 9.7 MB (93.25%)

class Solution {
   public:
    int firstMissingPositive(vector<int> &nums) {
        const int n = nums.size();
        // The result must be in [1, n + 1], so we don't care about the
        // negatives. Therefore we would use negative values as a flag of
        // having been "seen", as if we are using a hash set. To do so, we
        // must set the existing negatives and zeroes to (n + 1) first, which
        // is also not needed.
        for (auto &num : nums) {
            if (num <= 0) num = n + 1;
        }
        // Then we can set the flags. Since some flags may have already been
        // set earlier in this traversal, we use abs() to make sure we keep
        // those flags.
        for (int i = 0; i != n; ++i) {
            int ab = abs(nums[i]);
            if (ab <= n) nums[ab - 1] = -abs(nums[ab - 1]);
        }
        // The first negative value in our "hash set" would indicate that its
        // index + 1 has not been seen in the original array.
        for (int i = 0; i != n; ++i) {
            if (nums[i] > 0) return (i + 1);
        }
        // If all values have been seen, the smallest missing positive would
        // be (n + 1).
        return n + 1;
    }
};
