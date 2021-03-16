// Solved 2021-03-16 09:49
// Runtime: 4 ms (77.29%)
// Memory Usage: 6.6 MB (92.86%)

class Solution {
   public:
    bool halvesAreAlike(string s) {
        static const unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        const int len = s.length();
        int count = 0;
        for (int i = 0; i != len; ++i) {
            if (vowels.count(s[i])) count += (i < len / 2) ? 1 : -1;
        }
        return (count == 0);
    }
};
