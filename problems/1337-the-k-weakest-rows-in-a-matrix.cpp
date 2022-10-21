// Solved 2022-10-21
// Runtime: 16 ms (80.90%)
// Memory Usage: 10.5 MB (75.88%)

class Solution {
   public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
        auto count_soldiers = [](const vector<int> &row) {
            return lower_bound(row.begin(), row.end(), 0, greater<>{}) -
                   row.begin();
        };
        auto comp = [&](int lhs, int rhs) {
            int lhs_soldiers = count_soldiers(mat[lhs]);
            int rhs_soldiers = count_soldiers(mat[rhs]);
            return lhs_soldiers != rhs_soldiers ? lhs_soldiers > rhs_soldiers
                                                : lhs > rhs;
        };
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        for (int i = 0; i < mat.size(); ++i) {
            pq.push(i);
        }
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(pq.top());
            pq.pop();
        }
        return result;
    }
};
