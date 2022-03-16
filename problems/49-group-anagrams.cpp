// Solved 2022-03-16
// Runtime: 26 ms (97.18%)
// Memory Usage: 18.4 MB (92.32%)

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> groups;
        for (string &str : strs) {
            string key = str;
            sort(begin(key), end(key));
            if (groups.count(key) == 0) {
                groups[key] = vector<string>{str};
            } else {
                groups[key].push_back(str);
            }
        }
        vector<vector<string>> result;
        for (auto &entry : groups) {
            result.push_back(move(entry.second));
        }
        return result;
    }
};
