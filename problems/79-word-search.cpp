// Solved 2021-05-19 00:23
// Runtime: 140 ms (70.67%)
// Memory Usage: 7.2 MB (85.92%)

class Solution {
   public:
    bool exist(vector<vector<char>> &board, string word) {
        if (board.empty() || board[0].empty()) return false;
        if (word.empty()) return true;
        const int m = board.size(), n = board[0].size();
        if (m * n < word.length()) return false;  // this helps a lot!
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i != m; ++i) {
            for (int j = 0; j != n; ++j) {
                if (board[i][j] == word[0] && backtrack(board, word, 1, visited, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }

   private:
    bool backtrack(vector<vector<char>> &board, string &word, int index, vector<vector<bool>> &visited, int i, int j) {
        static constexpr int X[4]{1, 0, -1, 0}, Y[4]{0, 1, 0, -1};
        const int m = board.size(), n = board[0].size();
        if (index == word.length()) return true;
        visited[i][j] = true;
        for (int k = 0; k != 4; ++k) {
            int x = i + X[k], y = j + Y[k];
            if (x >= 0 && x < m && y >= 0 && y < n &&
                board[x][y] == word[index] && !visited[x][y] &&
                backtrack(board, word, index + 1, visited, x, y)) {
                return true;
            }
        }
        visited[i][j] = false;
        return false;
    }
};
