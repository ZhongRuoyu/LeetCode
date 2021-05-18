// Solved 2021-05-18 08:10
// Runtime: 0 ms (100.00%)
// Memory Usage: 11.3 MB (84.63%)

class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr;
        backtrack(res, curr, n, 0, 0);
        return res;
    }

   private:
    void backtrack(vector<string> &res, string &curr, int n, int open, int close) {
        if (curr.size() == n * 2) {
            res.emplace_back(curr);
        } else {
            if (open < n) {
                curr.push_back('(');
                backtrack(res, curr, n, open + 1, close);
                curr.pop_back();
            }
            if (close < open) {
                curr.push_back(')');
                backtrack(res, curr, n, open, close + 1);
                curr.pop_back();
            }
        }
    }
};
