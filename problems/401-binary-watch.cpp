// Solved 2021-05-25 11:10
// Runtime: 0 ms (100.00%)
// Memory Usage: 6.2 MB (95.53%)

class Solution {
   public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                if (countBits(h) + countBits(m) == turnedOn) {
                    res.emplace_back(to_string(h) + ":" + ((m < 10) ? "0" : "") + to_string(m));
                }
            }
        }
        return res;
    }

   private:
    int countBits(int x) {
        int cnt = 0;
        while (x) {
            ++cnt;
            x &= x - 1;
        }
        return cnt;
    }
};
