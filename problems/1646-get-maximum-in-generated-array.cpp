// Solved 2021-04-30 10:32
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.8 MB (98.39%)

class Solution {
   private:
    static constexpr array<int, 101> generateArray() {
        array<int, 101> nums{};
        nums[0] = 0;
        nums[1] = 1;
        for (int i = 2; i != 101; ++i) {
            nums[i] = nums[i / 2] + (i % 2 == 1 ? nums[i / 2 + 1] : 0);
        }
        for (int i = 1; i != 101; ++i) {
            if (nums[i - 1] > nums[i]) nums[i] = nums[i - 1];
        }
        return nums;
    }

   public:
    static int getMaximumGenerated(int n) {
        static constexpr array<int, 101> nums{generateArray()};
        return nums[n];
    }
};

// static constexpr array<int, 101> generateArray() makes the results
// calculated at compile time
