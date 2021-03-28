// Solved 2021-03-28 13:40
// Runtime: 4 ms (91.95%)
// Memory Usage: 6.5 MB (82.33%)

class Solution {
   public:
    string countAndSay(int n) {
        if (n <= 1) return "1";
        string strCount{countAndSay(n - 1)}, strSay;
        for (int i = 0, j = 0; i != strCount.size(); i = j) {
            while (++j != strCount.size() && strCount[i] == strCount[j]) continue;
            strSay.append(to_string(j - i) + strCount[i]);
        }
        return strSay;
    }
};
