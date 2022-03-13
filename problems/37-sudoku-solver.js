// Solved 2022-03-13
// Runtime: 95 ms (94.26%)
// Memory Usage: 44.8 MB (56.70%)

/**
 * @param {character[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var solveSudoku = function (board) {
    const newBoard = board.map(row => Array(...row));

    const rows = Array(9).fill(0);
    const columns = Array(9).fill(0);
    const blocks = [...Array(3)].map(() => Array(3).fill(0));
    const searchSpace = [];

    for (let i = 0; i < 9; ++i) {
        for (let j = 0; j < 9; ++j) {
            if (newBoard[i][j] > 0 && newBoard[i][j] <= 9) {
                flip(i, j, +newBoard[i][j]);
            }
        }
    }

    while (true) {
        let modified = false;
        for (let i = 0; i < 9; ++i) {
            for (let j = 0; j < 9; ++j) {
                if (!(newBoard[i][j] > 0 && newBoard[i][j] <= 9)) {
                    const available =
                        (~rows[i] & ~columns[j] & ~blocks[Math.floor(i / 3)][Math.floor(j / 3)]) &
                        0x1ff;
                    if (!available) {
                        return;
                    }
                    if (!(available & (available - 1))) {
                        const digit = getDigit(available);
                        flip(i, j, digit);
                        newBoard[i][j] = String(digit);
                        modified = true;
                    }
                }
            }
        }
        if (!modified) {
            break;
        }
    }

    for (let i = 0; i < 9; ++i) {
        for (let j = 0; j < 9; ++j) {
            if (!(newBoard[i][j] > 0 && newBoard[i][j] <= 9)) {
                searchSpace.push([i, j]);
            }
        }
    }

    if (dfs(0)) {
        newBoard.forEach((row, index) => board[index] = row);
    }



    function getDigit(x) {
        let digit = 1;
        for (; !(x & 1); x >>= 1) {
            ++digit;
        }
        return digit;
    }

    function flip(i, j, digit) {
        rows[i] ^= 1 << (digit - 1);
        columns[j] ^= 1 << (digit - 1);
        blocks[Math.floor(i / 3)][Math.floor(j / 3)] ^= 1 << (digit - 1);
    }

    function dfs(pos) {
        if (pos == searchSpace.length) {
            return true;
        }

        const [i, j] = searchSpace[pos];
        for (
            let available =
                (~rows[i] & ~columns[j] & ~blocks[Math.floor(i / 3)][Math.floor(j / 3)]) &
                0x1ff;
            available;
            available &= available - 1
        ) {
            const digit = getDigit(available);
            flip(i, j, digit);
            newBoard[i][j] = String(digit);
            if (dfs(pos + 1)) {
                return true;
            }
            flip(i, j, digit);
        }

        return false;
    }
};

// Please!!!
