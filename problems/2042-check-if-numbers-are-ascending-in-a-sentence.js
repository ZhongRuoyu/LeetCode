// Solved 2022-02-23
// Runtime: 49 ms (99.15%)
// Memory Usage: 41.4 MB (49.14%)

/**
 * @param {string} s
 * @return {boolean}
 */
var areNumbersAscending = function (s) {
    let prev = -Infinity;
    const tokens = s.split(" ");
    for (const token of tokens) {
        const num = Number.parseInt(token);
        if (!isNaN(num)) {
            if (prev >= token) {
                return false;
            }
            prev = num;
        }
    }
    return true;
};
