// Solved 2021-03-19 08:34
// Runtime: 0 ms (100.00%)
// Memory Usage: 6.1 MB (98.21%)

class Solution {
   public:
    int maxRepeating(string sequence, string word) {
        string max(word);
        int res = 0;
        while (sequence.find(max) != string::npos) {
            ++res;
            max.append(word);
        }
        return res;
    }
};
