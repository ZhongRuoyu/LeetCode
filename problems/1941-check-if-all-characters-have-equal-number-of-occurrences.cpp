// Solved 2022-02-06
// Runtime: 3 ms (83.99%)
// Memory Usage: 6.7 MB (61.79%)

class Solution {
   public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, unsigned> lookup;
        for (char ch : s) {
            ++lookup[ch];
        }
        int occurrences = lookup.begin()->second;
        return all_of(begin(lookup), end(lookup),
                      [=](auto entry) { return entry.second == occurrences; });
    }
};
