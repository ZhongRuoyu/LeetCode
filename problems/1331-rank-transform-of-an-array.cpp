// Solved 2021-05-16 10:21
// Runtime: 72 ms (87.32%)
// Memory Usage: 32 MB (95.37%)

class Solution {
   public:
    vector<int> arrayRankTransform(vector<int> &arr) {
        vector<int> indices(arr.size());
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(),
             [&arr](const int &x, const int &y) {
                 return arr[x] < arr[y];
             });
        for (int i = 0, rank = 1; i != arr.size(); ++rank) {
            int j = i, val = arr[indices[i]];
            while (j != arr.size() && arr[indices[j]] == val) {
                arr[indices[j++]] = rank;
            }
            i = j;
        }
        return arr;
    }
};
