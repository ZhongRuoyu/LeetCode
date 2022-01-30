// Solved 2022-01-30
// Runtime: 24 ms (92.19%)
// Memory Usage: 20.3 MB (64.12%)

class Solution {
   public:
    int maxProductDifference(vector<int> &nums) {
        int max1 = numeric_limits<int>::min() + 1;
        int max2 = numeric_limits<int>::min();
        int min1 = numeric_limits<int>::max() - 1;
        int min2 = numeric_limits<int>::max();
        for (int num : nums) {
            if (num > max2) {
                if (num > max1) {
                    max2 = max1;
                    max1 = num;
                } else {
                    max2 = num;
                }
            }
            if (num < min2) {
                if (num < min1) {
                    min2 = min1;
                    min1 = num;
                } else {
                    min2 = num;
                }
            }
        }
        return max1 * max2 - min1 * min2;
    }
};
