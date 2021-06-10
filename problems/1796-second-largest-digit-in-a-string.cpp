// Solved 2021-06-10
// Runtime: 0 ms (100.00%)
// Memory Usage: 6.6 MB (96.72%)

class Solution {
   public:
    int secondHighest(string s) {
        int d1(-1), d2(-1);
        for (auto &ch : s) {
            if (isdigit(ch)) {
                int d = ch - '0';
                if (d > d1) {
                    d2 = d1, d1 = d;
                } else if (d < d1 && d > d2) {
                    d2 = d;
                }
            }
        }
        return d2;
    }
};
