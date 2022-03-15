// Solved 2022-03-15
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.9 MB (75.95%)

class Solution {
   public:
    int divide(int dividend, int divisor) {
        if (dividend == numeric_limits<int>::min() && divisor == -1) {
            return numeric_limits<int>::max();
        }
        unsigned a = abs(dividend);
        unsigned b = abs(divisor);
        unsigned result = 0;
        for (unsigned shift = 31; shift != -1U && a >= b; --shift) {
            if ((a >> shift) >= b) {
                result += 1 << shift;
                a -= (b << shift);
            }
        }
        return (dividend > 0) ^ (divisor > 0) ? -result : result;
    }
};

// Fingers crossed... Good luck!
