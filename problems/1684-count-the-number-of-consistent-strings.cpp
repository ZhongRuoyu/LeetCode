// Solved 2021-05-02 09:47
// Runtime: 48 ms (87.14%)
// Memory Usage: 30.1 MB (83.50%)

class Solution {
   public:
    int countConsistentStrings(string allowed, vector<string> &words) {
        int count = 0;
        const char *c_allowed = allowed.c_str();
        for (auto &i : words) {
            if (strspn(i.c_str(), c_allowed) == i.size()) ++count;
        }
        return count;
    }
};
