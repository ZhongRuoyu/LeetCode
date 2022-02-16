// Solved 2022-02-16
// Runtime: 0 ms (100.00%)
// Memory Usage: 6.1 MB (93.47%)

class Solution {
   public:
    string reversePrefix(string word, char ch) {
        reverse(begin(word), begin(word) + word.find(ch) + 1);
        return word;
    }
};

/*

A more detailed version:

class Solution {
   public:
    string reversePrefix(string word, char ch) {
        size_t pos = word.find(ch);
        if (pos != string::npos) {
            reverse(begin(word), begin(word) + pos + 1);
        }
        return word;
    }
};

They are equivalent, because string::npos is defined as -1.

*/
