// Solved 2021-05-04 09:06
// Runtime: 0 ms (100.00%)
// Memory Usage: 9.1 MB (87.00%)

class Solution {
   public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) return "";
        string lcp{strs[0]};
        for (int i = 1; i != strs.size(); ++i) {
            lcp = longestCommonPrefix(lcp, strs[i]);
            if (lcp.empty()) return lcp;
        }
        return lcp;
    }

   private:
    string longestCommonPrefix(string &x, string &y) {
        int len = 0;
        while (len != x.size() && len != y.size() && x[len] == y[len]) ++len;
        return x.substr(0, len);
    }
};
