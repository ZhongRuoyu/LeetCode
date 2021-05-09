// Solved 2021-05-09 09:37
// Runtime: 0 ms (100.00%)
// Memory Usage: 9.5 MB (98.71%)

class Solution {
   public:
    bool isOneBitCharacter(vector<int> &bits) {
        const int n = bits.size() - 1;
        int i = 0;
        while (i < n) i += (bits[i] == 1) ? 2 : 1;
        return (i == n);
    }
};
