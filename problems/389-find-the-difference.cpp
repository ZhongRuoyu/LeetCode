// Solved 2021-03-01
// Runtime: 0 ms (100.00%)
// Memory Usage: 6.5 MB (87.30%)

class Solution {
   public:
    char findTheDifference(string s, string t) {
        char result = 0;
        for_each(begin(s), end(s), [&](char ch) { result ^= ch; });
        for_each(begin(t), end(t), [&](char ch) { result ^= ch; });
        return result;
    }
};
