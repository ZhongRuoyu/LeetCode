// Solved 2021-12-07
// Runtime: 96 ms (90.58%)
// Memory Usage: 67.6 MB (91.24%)

class Solution {
   public:
    int maxSubArray(vector<int> &nums) {
        int sum = 0;
        int max = numeric_limits<int>::min();
        for (size_t i = 0; i != nums.size(); ++i) {
            sum += nums[i];
            max = std::max(max, sum);
            sum = std::max(sum, 0);
        }
        return max;
    }
};

/*

A divide-and-conquer approach:

class Solution {
    struct Sums {
        int all_sum;
        int left_sum;
        int right_sum;
        int max_sum;
    };

   public:
    int maxSubArray(vector<int> &nums) {
        return maxSubArray(nums, 0, nums.size()).max_sum;
    }

   private:
    Sums Combine(Sums lhs, Sums rhs) {
        int all_sum = lhs.all_sum + rhs.all_sum;
        int left_sum = max(lhs.left_sum, lhs.all_sum + rhs.left_sum);
        int right_sum = max(rhs.right_sum, lhs.right_sum + rhs.all_sum);
        int max_sum =
            max(max(lhs.max_sum, rhs.max_sum), lhs.right_sum + rhs.left_sum);
        return (Sums){all_sum, left_sum, right_sum, max_sum};
    }

    Sums maxSubArray(vector<int> &nums, size_t start, size_t end) {
        if (start + 1 == end) {
            return (Sums){nums[start], nums[start], nums[start], nums[start]};
        }
        size_t mid = start + (end - start) / 2;
        Sums lhs = maxSubArray(nums, start, mid);
        Sums rhs = maxSubArray(nums, mid, end);
        return Combine(lhs, rhs);
    }
};

*/
