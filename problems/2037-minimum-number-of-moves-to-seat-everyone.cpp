// Solved 2022-02-22
// Runtime: 7 ms (88.08%)
// Memory Usage: 18.1 MB (87.87%)

class Solution {
   public:
    int minMovesToSeat(vector<int> &seats, vector<int> &students) {
        sort(begin(seats), end(seats));
        sort(begin(students), end(students));
        int moves = 0;
        for (size_t i = 0; i != seats.size(); ++i) {
            moves += abs(seats[i] - students[i]);
        }
        return moves;
    }
};
