// Solved 2021-04-08 09:04
// Runtime: 52 ms (76.42%)
// Memory Usage: 15.6 MB (82.44%)

class Solution {
   public:
    int countCharacters(vector<string> &words, string chars) {
        unordered_map<char, int> ref;  // this copy as a reference
        for (auto &ch : chars) {
            ++ref[ch];
        }
        unordered_map<char, int> lookup(ref.begin(), ref.end());
        int res = 0;
        for (auto &word : words) {
            int i = 0;
            while (i != word.size() && --lookup[word[i]] >= 0) ++i;
            if (i == word.size()) res += word.size();

            // reset lookup
            for (auto &item : lookup) {
                item.second = ref[item.first];
            }
        }
        return res;
    }
};
