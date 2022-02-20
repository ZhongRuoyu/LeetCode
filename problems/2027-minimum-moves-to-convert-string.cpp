// Solved 2022-02-20
// Runtime: 0 ms (100.00%)
// Memory Usage: 6.4 MB (84.51%)

class Solution {
   public:
    int minimumMoves(string s) {
        int count = 0;
        for (size_t i = 0; i < s.length(); i += s[i] == 'O' ? 1 : 3) {
            if (s[i] != 'O') ++count;
        }
        return count;
    }
};
