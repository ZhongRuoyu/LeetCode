// Solved 2021-12-16
// Runtime: 20 ms (77.97%)
// Memory Usage: 23.2 MB (75.88%)

class Solution {
   public:
    void reverseString(vector<char> &s) {
        auto l = begin(s);
        auto r = end(s) - 1;
        while (l < r) {
            swap(*l++, *r--);
        }
    }
};
