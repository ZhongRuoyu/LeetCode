// Solved 2022-02-07
// Runtime: 0 ms (100.00%)
// Memory Usage: 6 MB (99.69%)

class Solution {
   public:
    int getLucky(string s, int k) {
        int sum = 0;
        for (char ch : s) {
            ch -= 'a' - 1;
            sum += ch / 10 + ch % 10;
        }
        while (--k > 0 && sum > 9) {
            int t = 0;
            while (sum != 0) {
                t += sum % 10;
                sum /= 10;
            }
            sum = t;
        }
        return sum;
    }
};
