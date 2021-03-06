// Solved 2021-03-06 10:51
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.7 MB (91.04%)

class Solution {
   public:
    string convertToTitle(int n) {
        string ans;
        while (n) {
            ans = (char)(--n % 26 + 'A') + ans;
            n /= 26;
        }
        return ans;
    }
};
