// Solved 2021-03-22 10:56
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.9 MB (84.80%)

class Solution {
   public:
    int numPrimeArrangements(int n) {
        vector<bool> isPrime(n + 1, true);
        long long res = 1;
        int prime = 0, nonprime = 1,
            i, j;
        for (i = 2; i <= n; ++i) {
            if (isPrime[i]) {
                for (j = i * i; j <= n; j += i) isPrime[j] = false;
                res = res * ++prime % 1000000007L;
            } else {
                res = res * ++nonprime % 1000000007L;
            }
        }
        return res;
    }
};
