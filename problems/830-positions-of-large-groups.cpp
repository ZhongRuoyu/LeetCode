// Solved 2021-03-05 12:50
// Runtime: 0 ms (100.00%)
// Memory Usage: 7.3 MB (86.88%)

class Solution {
   public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        int i = 0, j;
        while (i < s.size()) {
            j = i + 1;
            while (j < s.size() && s[i] == s[j]) ++j;
            // j < s.size() seems to be unnecessary here
            // but the behaviour is undefined when j == s.size()
            // as a past-the-end iterator should not be dereferenced
            if (j - i >= 3) ans.push_back({i, j - 1});
            i = j;
        }
        return ans;
    }
};
