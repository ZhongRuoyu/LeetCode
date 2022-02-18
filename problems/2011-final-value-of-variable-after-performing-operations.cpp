// Solved 2022-02-18
// Runtime: 0 ms (100.00%)
// Memory Usage: 14 MB (58.94%)

class Solution {
   public:
    int finalValueAfterOperations(vector<string> &operations) {
        int x = 0;
        for (string &operation : operations) {
            if (operation == "++X" || operation == "X++") {
                ++x;
            } else if (operation == "--X" || operation == "X--") {
                --x;
            }
        }
        return x;
    }
};
