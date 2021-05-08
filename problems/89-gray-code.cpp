// Solved 2021-05-08 08:11
// Runtime: 4 ms (96.00%)
// Memory Usage: 11.2 MB (90.46%)

class Solution {
   public:
    vector<int> grayCode(int n) {
        vector<int> res(1 << n);
        for (int i = 0; i != res.size(); ++i) {
            res[i] = i ^ (i >> 1);
        }
        return res;
    }
};

// Gray code: https://en.wikipedia.org/wiki/Gray_code#Converting_to_and_from_Gray_code

/* 

Another solution:

class Solution {
   public:
    vector<int> grayCode(int n) {
        vector<int> res{0};
        for (int i = 0; i != n; ++i) {
            int setbit = 1 << i;
            for (int j = res.size() - 1; j != -1; --j) {
                res.emplace_back(setbit | res[j]);
            }
        }
        return res;
    }
};

*/
