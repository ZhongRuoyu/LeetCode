// Solved 2022-02-04
// Runtime: 0 ms (100.00%)
// Memory Usage: 6.6 MB (85.93%)

class Solution {
   public:
    int canBeTypedWords(string text, string brokenLetters) {
        array<bool, 26> is_broken{};
        for (char letter : brokenLetters) {
            is_broken[letter - 'a'] = true;
        }
        int result = 0;
        int broken = 0;
        for (size_t i = 0; i <= text.length(); ++i) {
            if (text[i] == ' ' || i == text.length()) {
                if (broken == 0) {
                    ++result;
                }
                broken = 0;
            } else {
                if (is_broken[text[i] - 'a']) {
                    ++broken;
                }
            }
        }
        return result;
    }
};
