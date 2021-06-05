// Solved 2021-06-05 14:11
// Runtime: 0 ms (100.00%)
// Memory Usage: 6.2 MB (90.19%)

class Solution {
   public:
    string mergeAlternately(string word1, string word2) {
        string res;
        for (int i = 0; i != word1.size() && i != word2.size(); ++i) {
            res.push_back(word1[i]);
            res.push_back(word2[i]);
        }
        if (word1.size() < word2.size()) {
            res.append(word2.begin() + word1.size(), word2.end());
        } else {
            res.append(word1.begin() + word2.size(), word1.end());
        }
        return res;
    }
};
