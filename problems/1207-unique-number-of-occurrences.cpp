// Solved 2021-04-07 13:05
// Runtime: 0 ms (100.00%)
// Memory Usage: 8 MB (74.59%)

class Solution {
   public:
    bool uniqueOccurrences(vector<int> &arr) {
        unordered_map<int, int> cnt;
        for (auto &num : arr) {
            ++cnt[num];
        }
        unordered_set<int> occurrences;
        for (auto &i : cnt) {
            if (occurrences.find(i.second) != occurrences.end()) return false;
            occurrences.insert(i.second);
        }
        return true;
    }
};
