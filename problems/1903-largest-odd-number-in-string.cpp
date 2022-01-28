// Solved 2022-01-28
// Runtime: 24 ms (95.29%)
// Memory Usage: 14.9 MB (64.90%)

class Solution {
   public:
    string largestOddNumber(string num) {
        return num.substr(0, num.find_last_of("13579") + 1);
    }
};
