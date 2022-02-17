// Solved 2022-02-17
// Runtime: 7 ms (96.29%)
// Memory Usage: 12.3 MB (95.21%)

class Solution {
   public:
    int countKDifference(vector<int> &nums, int k) {
        array<int, 101> counts{};
        for (int num : nums) {
            ++counts[num];
        }
        int count = 0;
        for (int i = k + 1; i <= 100; ++i) {
            count += counts[i - k] * counts[i];
        }
        return count;
    }
};
