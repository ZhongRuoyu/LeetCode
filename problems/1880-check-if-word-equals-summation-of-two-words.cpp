// Solved 2022-01-25
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.8 MB (96.46%)

class Solution {
   public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return toNumericalValue(firstWord) + toNumericalValue(secondWord) ==
               toNumericalValue(targetWord);
    }

   private:
    unsigned toNumericalValue(string s) {
        unsigned value = 0;
        for (size_t i = 0; i < s.length(); ++i) {
            value = value * 10 + s[i] - 'a';
        }
        return value;
    }
};
