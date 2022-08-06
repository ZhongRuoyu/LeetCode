// Solved 2022-08-06
// Runtime: 101 ms (91.97%)
// Memory Usage: 16.5 MB (29.13%)

class Solution {
   public:
    vector<int> countPoints(vector<vector<int>> &points,
                            vector<vector<int>> &queries) {
        struct Point {
            int x;
            int y;
        };

        vector<Point> processed_points;
        for (const auto &point : points) {
            processed_points.push_back(Point{.x = point[0], .y = point[1]});
        }
        sort(begin(processed_points), end(processed_points),
             [](auto lhs, auto rhs) { return lhs.x < rhs.x; });

        vector<int> answer;
        for (const auto &query : queries) {
            int count = 0;
            for (auto it =
                     lower_bound(begin(processed_points), end(processed_points),
                                 Point{.x = query[0] - query[2], .y = 0},
                                 [](const auto &lhs, const auto &rhs) {
                                     return lhs.x < rhs.x;
                                 });
                 it != end(processed_points) && it->x <= query[0] + query[2];
                 ++it)
                if ((query[0] - it->x) * (query[0] - it->x) +
                        (query[1] - it->y) * (query[1] - it->y) <=
                    query[2] * query[2]) {
                    ++count;
                }
            answer.push_back(count);
        }

        return answer;
    }
};
