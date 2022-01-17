// Solved 2022-01-17
// Runtime: 12 ms (89.75%)
// Memory Usage: 8.8 MB (72.61%)

class Solution {
   public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> map(26, 0);
        for (char ch : magazine) {
            ++map[ch - 'a'];
        }
        for (char ch : ransomNote) {
            if (--map[ch - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
