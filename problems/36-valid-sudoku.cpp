// Solved 2021-05-28 16:30
// Runtime: 12 ms (98.26%)
// Memory Usage: 17.8 MB (95.51%)

class Solution {
   public:
    bool isValidSudoku(vector<vector<char>> &board) {
        array<int, 9> a{};
        for (int i = 0; i != 9; ++i) {
            for (int j = 0; j != 9; ++j) {
                if (board[i][j] != '.') {
                    int t = board[i][j] - '1';
                    if (a[i] & 1 << t ||
                        a[j] & 1 << (t + 9) ||
                        a[3 * (i / 3) + j / 3] & 1 << (t + 18)) {
                        return false;
                    }
                    a[i] |= 1 << t;
                    a[j] |= 1 << (t + 9);
                    a[3 * (i / 3) + j / 3] |= 1 << (t + 18);
                }
            }
        }
        return true;
    }
};
