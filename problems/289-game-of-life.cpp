// Solved 2021-02-14 12:30
// Runtime: 0 ms (100.00%)
// Memory Usage: 6.9 MB (96.35%)

class Solution {
   public:
    void gameOfLife(vector<vector<int>> &board) {
        static constexpr int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1},
                             dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
        const int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int neighbour = 0;
                for (int k = 0; k < 8; ++k) {
                    int xc = i + dx[k],
                        yc = j + dy[k];
                    if (xc >= 0 && xc < m &&
                        yc >= 0 && yc < n &&
                        (board[xc][yc] & 1)) {
                        ++neighbour;
                    }
                }
                if ((neighbour == 3) || ((board[i][j] & 1) && neighbour == 2)) {
                    board[i][j] |= 2;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] >>= 1;
            }
        }
    }
};
