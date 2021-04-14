// Solved 2021-04-14 10:02
// Runtime: 40 ms (87.69%)
// Memory Usage: 21.6 MB (79.44%)

class Solution {
   public:
    int leastBricks(vector<vector<int>> &wall) {
        unordered_map<int, int> map;
        for (auto &row : wall) {
            for (int i = 0, pos = 0; i != row.size() - 1; ++i) {
                ++map[pos += row[i]];
            }
        }
        if (map.empty()) return wall.size();
        return wall.size() -
               max_element(
                   map.begin(), map.end(),
                   [](const pair<int, int> &x, const pair<int, int> &y) {
                       return (x.second < y.second);
                   })
                   ->second;
    }
};
