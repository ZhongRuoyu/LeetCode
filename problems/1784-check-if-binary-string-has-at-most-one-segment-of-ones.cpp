// Solved 2021-06-08 22:16
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.9 MB (90.62%)

class Solution {
   public:
    bool checkOnesSegment(string s) {
        return s.find("01") == string::npos;
    }
};
