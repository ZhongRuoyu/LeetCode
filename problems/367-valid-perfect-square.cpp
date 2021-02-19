// Solved 2021-02-19 11:01
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.7 MB (99.29%)

class Solution {
   public:
    bool isPerfectSquare(int num) {
        for (int i = 1; num > 0; i += 2) {
            num -= i;
        }
        return (num == 0);
    }
};
