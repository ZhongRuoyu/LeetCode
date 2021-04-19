// Solved 2021-04-19 10:08
// Runtime: 0 ms (100.00%)
// Memory Usage: 8.4 MB (80.18%)

class Solution {
   public:
    int uniqueMorseRepresentations(vector<string> &words) {
        static const string alphabet[26]{
            ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
            "....", "..", ".---", "-.-", ".-..", "--", "-.",
            "---", ".--.", "--.-", ".-.", "...", "-", "..-",
            "...-", ".--", "-..-", "-.--", "--.."};
        unordered_set<string> morse;
        for (auto &word : words) {
            string code;
            for (auto &ch : word) code.append(alphabet[ch - 'a']);
            morse.insert(code);
        }
        return morse.size();
    }
};
