// Solved 2022-07-16
// Runtime: 0 ms (100.00%)
// Memory Usage: 6.1 MB (83.15%)

class Solution {
   public:
    int percentageLetter(string s, char letter) {
        return count(begin(s), end(s), letter) * 100 / s.size();
    }
};
