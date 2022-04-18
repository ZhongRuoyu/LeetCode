// Solved 2022-04-18
// Runtime: 55 ms (100.00%)
// Memory Usage: 42.6 MB (90.70%)

/**
 * @param {number[][]} grid
 * @return {number}
 */
var projectionArea = function (grid) {
    const n = grid.length;
    let result = 0;
    for (let i = 0; i < n; ++i) {
        let maxRow = 0;
        let maxCol = 0;
        for (let j = 0; j < n; ++j) {
            if (grid[i][j] > 0) {
                ++result;
            }
            maxRow = Math.max(maxRow, grid[i][j]);
            maxCol = Math.max(maxCol, grid[j][i]);
        }
        result += maxRow + maxCol;
    }
    return result;
};
