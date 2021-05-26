// Solved 2021-05-26 10:35
// Runtime: 4 ms (91.91%)
// Memory Usage: 5.8 MB (91.16%)

class Solution {
   public:
    int numTilePossibilities(string tiles) {
        map<char, int> m;
        for (auto &ch : tiles) ++m[ch];
        return calculate(m);
    }

   private:
    int calculate(map<char, int> &m) {
        int cnt = 0;
        for (auto &i : m) {
            if (i.second > 0) {
                --i.second;
                cnt += calculate(m) + 1;
                ++i.second;
            }
        }
        return cnt;
    }
};
