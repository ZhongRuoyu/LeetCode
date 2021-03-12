// Solved 2021-03-13 00;03
// Runtime: 28 ms (84.52%)
// Memory Usage: 24.7 MB (96.07%)

class Solution {
   public:
    vector<int> decode(vector<int> &encoded, int first) {
        encoded.insert(encoded.begin(), first);
        for (int i = 1; i != encoded.size(); ++i) {
            encoded[i] ^= encoded[i - 1];
        }
        return encoded;
    }
};
