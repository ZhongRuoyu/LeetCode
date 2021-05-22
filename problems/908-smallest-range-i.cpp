// Solved 2021-05-22 15:31
// Runtime: 12 ms (87.64%)
// Memory Usage: 15.4 MB (88.76%)

class Solution {
   public:
    int smallestRangeI(vector<int> &A, int K) {
        int max = A[0], min = A[0];
        for (auto &i : A) {
            if (i > max) max = i;
            if (i < min) min = i;
        }
        return (max - min > 2 * K) ? (max - min - 2 * K) : 0;
    }
};
