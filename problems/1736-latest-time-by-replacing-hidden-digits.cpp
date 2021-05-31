// Solved 2021-05-31 09:39
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.8 MB (85.98%)

class Solution {
   public:
    string maximumTime(string time) {
        if (time[0] == '?') time[0] = (time[1] == '?' || time[1] < '4') ? '2' : '1';
        if (time[1] == '?') time[1] = (time[0] == '2') ? '3' : '9';
        if (time[3] == '?') time[3] = '5';
        if (time[4] == '?') time[4] = '9';
        return time;
    }
};
