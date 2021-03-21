// Solved 2021-03-21 15:29
// Runtime: 16 ms (88.38%)
// Memory Usage: 20.2 MB (84.22%)

class Solution {
   public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        int prev = 0, countEmpty = 1, maxFlowers = 0;
        for (int i = 0; i != flowerbed.size(); ++i) {
            if (flowerbed[i] == 1) {
                if (prev == 0) {
                    maxFlowers += (countEmpty - 1) / 2;
                    countEmpty = 0;
                }
            } else {
                ++countEmpty;
            }
            prev = flowerbed[i];
        }
        maxFlowers += countEmpty / 2;
        return (maxFlowers >= n);
    }
};
