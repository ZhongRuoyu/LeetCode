// Solved 2021-03-14 15:20
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.7 MB (97.91%)

class Solution {
   public:
    int totalMoney(int n) {
        const int x = n / 7, y = n % 7;
        return (x + 7) * x * 7 / 2 + (2 * x + y + 1) * y / 2;
    }
};
