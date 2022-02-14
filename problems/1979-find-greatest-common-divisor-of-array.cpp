// Solved 2022-02-14
// Runtime: 0 ms (100.00%)
// Memory Usage: 12.3 MB (93.38%)

class Solution {
   public:
    int findGCD(vector<int> &nums) {
        int min = numeric_limits<int>::max();
        int max = numeric_limits<int>::min();
        for (int num : nums) {
            min = std::min(min, num);
            max = std::max(max, num);
        }
        return gcd(min, max);
    }
};
