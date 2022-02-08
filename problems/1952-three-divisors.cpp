// Solved 2022-02-08
// Runtime: 0 ms (100.00%)
// Memory Usage: 6 MB (99.69%)

class Solution {
   public:
    bool isThree(int n) {
        if (n <= 1) {
            return false;
        }
        int count = 0;
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                count += (i * i == n) ? 1 : 2;
            }
        }
        return count == 3;
    }
};

// class Solution {
//    public:
//     bool isThree(int n) {
//         unordered_set<int> primes{2,  3,  5,  7,  11, 13, 17, 19, 23,
//                                   29, 31, 37, 41, 43, 47, 53, 59, 61,
//                                   67, 71, 73, 79, 83, 89, 97};
//         return (int)sqrt(n) * (int)sqrt(n) == n &&
//                primes.count((int)sqrt(n)) != 0;
//     }
// };
