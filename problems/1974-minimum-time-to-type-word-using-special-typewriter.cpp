// Solved 2022-02-13
// Runtime: 0 ms (100.00%)
// Memory Usage: 6.1 MB (89.34%)

class Solution {
   public:
    int minTimeToType(string word) {
        char prev = 'a';
        int time = 0;
        for (char curr : word) {
            time += min(abs(curr - prev), 26 - abs(curr - prev)) + 1;
            prev = curr;
        }
        return time;
    }
};
