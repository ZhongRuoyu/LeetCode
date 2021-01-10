// Solved 2021-01-11 07:54
// Runtime: 0 ms (100.00%)
// Memory Usage: 6.4 MB (73.09%)

class Solution {
   public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        return ceil(log(buckets) / log(minutesToTest / minutesToDie + 1));
    }
};
