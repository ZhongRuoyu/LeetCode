// Solved 2022-04-10
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.7 MB (96.23%)

class Solution {
   public:
    string toHex(int num) {
        string result;
        for (int i = 7; i >= 0; --i) {
            int digit = (num >> (i * 4)) & 0xf;
            if (result.size() == 0 && digit == 0) {
                continue;
            }
            result.push_back(digit < 10 ? '0' + digit : 'a' + digit - 10);
        }
        return result.length() > 0 ? result : "0";
    }
};
