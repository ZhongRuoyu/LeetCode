// Solved 2022-02-11
// Runtime: 5 ms (66.78%)
// Memory Usage: 8.7 MB (66.08%)

class Solution {
   public:
    int numOfStrings(vector<string> &patterns, string word) {
        return count_if(patterns.begin(), patterns.end(), [&](string pattern) {
            return word.find(pattern) != string::npos;
        });
    }
};
