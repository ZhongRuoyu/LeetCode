// Solved 2021-01-20 08:39
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.7 MB (100.00%)

class Solution {
   public:
    int findComplement(int num) {
        unsigned mask = -1;
        while (num & mask) mask <<= 1;
        return ~(num | mask);
    }
};
