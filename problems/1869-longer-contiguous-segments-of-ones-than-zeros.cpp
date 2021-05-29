// Solved 2021-05-29 11:32
// Runtime: 0 ms (100.00%)
// Memory Usage: 6 MB (68.14%)

class Solution {
   public:
    bool checkZeroOnes(string s) {
        int cnt[2]{}, max_cnt[2]{};
        for (auto &ch : s) {
            max_cnt[ch - '0'] = max(max_cnt[ch - '0'], ++cnt[ch - '0']);
            cnt['1' - ch] = 0;
        }
        return max_cnt[1] > max_cnt[0];
    }
};
