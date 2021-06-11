// Solved 2021-06-12
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.8 MB (85.90%)

class Solution {
   public:
    bool squareIsWhite(string coordinates) {
        return (coordinates[0] + coordinates[1]) % 2 == 1;
    }
};
