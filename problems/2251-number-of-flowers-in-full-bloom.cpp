// Solved 2022-08-09
// Runtime: 366 ms (86.86%)
// Memory Usage: 82.2 MB (71.59%)

class Solution {
   public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers,
                                 vector<int> &persons) {
        vector<int> start;
        vector<int> end;
        for (const auto &flower : flowers) {
            start.push_back(flower[0]);
            end.push_back(flower[1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        vector<int> answer;
        for (auto person : persons) {
            int started =
                upper_bound(start.begin(), start.end(), person) - start.begin();
            int ended =
                lower_bound(end.begin(), end.end(), person) - end.begin();
            answer.push_back(started - ended);
        }

        return answer;
    }
};
