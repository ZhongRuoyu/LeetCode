// Solved 2021-06-02 09:53
// Runtime: 4 ms (99.12%)
// Memory Usage: 5.9 MB (89.83%)

class Solution {
   public:
    int countBalls(int lowLimit, int highLimit) {
        array<int, 45> c{};
        for (int i = lowLimit; i <= highLimit; ++i) {
            ++c[sum_digits(i) - 1];
        }
        return *max_element(c.begin(), c.end());
    }

   private:
    int sum_digits(int n) {
        int res = 0;
        while (n) {
            res += n % 10;
            n /= 10;
        }
        return res;
    }
};
