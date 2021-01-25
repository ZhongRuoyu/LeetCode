// Solved 2021-01-25 08:33
// Runtime: 0 ms (100.00%)
// Memory Usage: 7.4 MB (90.36%)

class Solution {
   public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<int> queens(n, -1);
        solve(solutions, queens, n);
        return solutions;
    }

   private:
    void solve(vector<vector<string>> &solutions, vector<int> &queens, int n, int row = 0, int columns = 0, int diagonals1 = 0, int diagonals2 = 0) {
        if (row == n) {
            solutions.emplace_back(generateBoard(queens, n));
        } else {
            int availablePositions = ((1 << n) - 1) & (~(columns | diagonals1 | diagonals2));
            while (availablePositions) {
                int columnPosition = availablePositions & (-availablePositions);  // get lowest set bit
                availablePositions &= ~columnPosition;                            // clear that bit
                queens[row] = getLowestSetBitPosition(columnPosition);            // get current position
                solve(solutions, queens, n, row + 1, columns | columnPosition, (diagonals1 | columnPosition) >> 1, (diagonals2 | columnPosition) << 1);
                queens[row] = -1;
            }
        }
    }

    vector<string> generateBoard(vector<int> &queens, int n) {
        vector<string> board;
        for (int i = 0; i < n; ++i) {
            board.emplace_back(string(n, '.'));
            board[i][queens[i]] = 'Q';
        }
        return board;
    }

    constexpr int getLowestSetBitPosition(int n) {
        int position = 0;
        while (n >>= 1) ++position;
        return position;
    }
};

// See also: Problem 52 (N-Queens II)
