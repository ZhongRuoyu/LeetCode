// Solved 2021-01-21 08:28
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.9 MB (96.89%)

class Solution {
   public:
    int bitwiseComplement(int N) {
        if (N == 0) return 1;
        unsigned mask = -1;
        while (N & mask) mask <<= 1;
        return ~(N | mask);
    }
};
