// Solved 2021-06-06 14:16
// Runtime: 64 ms (92.98%)
// Memory Usage: 30.8 MB (96.40%)

class Solution {
   public:
    int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue) {
        int rule_index = ruleKey == "type"    ? 0
                         : ruleKey == "color" ? 1
                                              : 2;
        int c = 0;
        for (auto it = items.begin(); it != items.end(); ++it) {
            if ((*it)[rule_index] == ruleValue) ++c;
        }
        return c;
    }
};
