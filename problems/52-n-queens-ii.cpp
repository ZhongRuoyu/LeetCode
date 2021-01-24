// Solved 2021-01-24 11:02
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.7 MB (99.69%)

class Solution {
   public:
    int totalNQueens(int n) {
        int total = 0;
        solve(n, total);
        return total;
    }

   private:
    void solve(int n, int &total, int row = 0, int columns = 0, int diagonals1 = 0, int diagonals2 = 0) {
        if (row == n) {
            ++total;
        } else {
            int availablePositions = ((1 << n) - 1) & (~(columns | diagonals1 | diagonals2));
            while (availablePositions) {
                int columnPosition = availablePositions & (-availablePositions);  // get lowest set bit
                availablePositions &= ~columnPosition;                            // clear that bit
                solve(n, total, row + 1, columns | columnPosition, (diagonals1 | columnPosition) >> 1, (diagonals2 | columnPosition) << 1);
            }
        }
    }
};

// See also: Problem 51 (N-Queens)
