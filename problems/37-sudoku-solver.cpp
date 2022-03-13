// Solved 2022-03-13
// Runtime: 3 ms (99.04%)
// Memory Usage: 17.4 MB (9.88%)

class Solution {
    constexpr int get_digit(uint16_t x) {
        int digit = 1;
        for (; !(x & 1); x >>= 1) {
            ++digit;
        }
        return digit;
    }

    void flip(vector<uint16_t> &rows, vector<uint16_t> &columns,
              vector<vector<uint16_t>> &blocks, size_t i, size_t j, int digit) {
        rows[i] ^= 1 << (digit - 1);
        columns[j] ^= 1 << (digit - 1);
        blocks[i / 3][j / 3] ^= 1 << (digit - 1);
    }

    bool dfs(vector<vector<char>> &board, vector<uint16_t> &rows,
             vector<uint16_t> &columns, vector<vector<uint16_t>> &blocks,
             vector<pair<size_t, size_t>> search_space, size_t pos) {
        if (pos == search_space.size()) {
            return true;
        }

        auto [i, j] = search_space[pos];

        for (uint16_t available =
                 (~rows[i] & ~columns[j] & ~blocks[i / 3][j / 3]) &
                 0b1'1111'1111;
             available; available &= available - 1) {
            int digit = get_digit(available);
            flip(rows, columns, blocks, i, j, digit);
            board[i][j] = '0' + digit;
            if (dfs(board, rows, columns, blocks, search_space, pos + 1)) {
                return true;
            }
            flip(rows, columns, blocks, i, j, digit);
        }

        return false;
    }

   public:
    void solveSudoku(vector<vector<char>> &board) {
        vector<vector<char>> new_board(board);

        vector<uint16_t> rows(9);
        vector<uint16_t> columns(9);
        vector<vector<uint16_t>> blocks(3, vector<uint16_t>(3));
        vector<pair<size_t, size_t>> search_space;

        for (size_t i = 0; i < 9; ++i) {
            for (size_t j = 0; j < 9; ++j) {
                if (isdigit(new_board[i][j])) {
                    flip(rows, columns, blocks, i, j, new_board[i][j] - '0');
                }
            }
        }

        while (true) {
            bool modified = false;
            for (size_t i = 0; i < 9; ++i) {
                for (size_t j = 0; j < 9; ++j) {
                    if (!isdigit(new_board[i][j])) {
                        uint16_t available =
                            (~rows[i] & ~columns[j] & ~blocks[i / 3][j / 3]) &
                            0b1'1111'1111;
                        if (!available) {
                            return;
                        }
                        if (!(available & (available - 1))) {
                            int digit = get_digit(available);
                            flip(rows, columns, blocks, i, j, digit);
                            new_board[i][j] = '0' + digit;
                            modified = true;
                        }
                    }
                }
            }
            if (!modified) {
                break;
            }
        }

        for (size_t i = 0; i < 9; ++i) {
            for (size_t j = 0; j < 9; ++j) {
                if (!isdigit(new_board[i][j])) {
                    search_space.emplace_back(i, j);
                }
            }
        }

        if (dfs(new_board, rows, columns, blocks, search_space, 0)) {
            board = new_board;
        }
    }
};

// Please!!!
