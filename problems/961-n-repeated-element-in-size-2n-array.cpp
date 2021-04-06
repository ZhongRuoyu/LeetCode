// Solved 2021-04-06 09:19
// Runtime: 24 ms (94.36%)
// Memory Usage: 24.6 MB (96.52%)

class Solution {
   public:
    int repeatedNTimes(vector<int> &A) {
        unordered_set<int> lookup;
        for (auto &num : A) {
            if (lookup.find(num) != lookup.end()) return num;
            lookup.insert(num);
        }
        return 0;
    }
};
