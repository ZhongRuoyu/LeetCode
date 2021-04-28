// Solved 2021-04-28 08:23
// Runtime: 0 ms (100.00%)
// Memory Usage: 7.1 MB (98.80%)

class Solution {
   public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n);
        int i;
        for (i = 1; i <= n; i++) ans[i - 1] = to_string(i);
        for (i = 2; i < n; i += 3) ans[i] = "Fizz";
        for (i = 4; i < n; i += 5) ans[i] = "Buzz";
        for (i = 14; i < n; i += 15) ans[i] = "FizzBuzz";
        return ans;
    }
};
