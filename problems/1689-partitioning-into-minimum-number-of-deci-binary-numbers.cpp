// Solved 2021-05-03 09:30
// Runtime: 28 ms (93.96%)
// Memory Usage: 13.5 MB (72.47%)

class Solution {
   public:
    int minPartitions(string n) {
        return *max_element(n.begin(), n.end()) - '0';
    }
};
