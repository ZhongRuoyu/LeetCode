// Solved 2021-04-13 09:31
// Runtime: 0 ms (100.00%)
// Memory Usage: 6.4 MB (83.65%)

class Solution {
   public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> res{""};
        static const unordered_map<char, string> mapping{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}};
        while (digits.size()) {
            vector<string> temp;
            for (auto &str : res) {
                for (auto &ch : mapping.at(digits[0])) {
                    temp.push_back(str + ch);
                }
            }
            res.swap(temp);
            digits.erase(digits.begin());
        }
        return res;
    }
};
