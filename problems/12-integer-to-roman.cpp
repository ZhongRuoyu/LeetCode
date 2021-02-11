// Solved 2021-02-11 08:01
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.9 MB (93.13%)

class Solution {
   public:
    string intToRoman(int num) {
        static const vector<pair<int, string>> lookup{
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}};
        string res;
        for (auto &i : lookup) {
            if (num == 0) break;
            while (num >= i.first) {
                res.append(i.second);
                num -= i.first;
            }
        }
        return res;
    }
};

/* 

A brute-force approach:

class Solution {
   public:
    string intToRoman(int num) {
        string M[] = {"", "M", "MM", "MMM"};
        string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return M[num / 1000] + C[(num % 1000) / 100] + X[(num % 100) / 10] + I[num % 10];
    }
};

*/

// See also: Problem 13 (Roman to Integer)

// Happy New Year
