// Solved 2021-03-18 08:01
// Runtime: 4 ms (89.92%)
// Memory Usage: 11 MB (99.80%)

// A two-pointer approach

class Solution {
   public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2) {
        int w1 = 0, i1 = 0, w2 = 0, i2 = 0;
        while (w1 < word1.size() && w2 < word2.size()) {
            if (word1[w1][i1] != word2[w2][i2]) return false;
            if (++i1 == word1[w1].length()) {
                i1 = 0;
                ++w1;
            }
            if (++i2 == word2[w2].length()) {
                i2 = 0;
                ++w2;
            }
        }
        if (w1 < word1.size() || w2 < word2.size()) return false;
        return true;
    }
};

/*

A straightforward approach using string concatenation:

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1, str2;
        for (auto &word : word1) {
            str1.append(word);
        }
        for (auto &word : word2) {
            str2.append(word);
        }
        return (str1 == str2);
    }
};

*/
