// Solved 2021-06-13
// Runtime: 4 ms (91.14%)
// Memory Usage: 10.1 MB (83.73%)

class Solution {
   public:
    int arraySign(vector<int> &nums) {
        return accumulate(
            nums.begin(), nums.end(), 1,
            [&](int &x, int &y) { return y > 0   ? x
                                         : y < 0 ? -x
                                                 : 0; });
    }
};
