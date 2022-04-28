// Solved 2022-04-28
// Runtime: 63 ms (85.71%)
// Memory Usage: 42.1 MB (53.71%)

/**
 * @param {number[]} colors
 * @return {number}
 */
var maxDistance = function (colors) {
    const n = colors.length;
    let i = 0;
    let j = n - 1;
    while (colors[i] === colors[n - 1]) {
        ++i;
    }
    while (colors[j] === colors[0]) {
        --j;
    }
    return Math.max(n - 1 - i, j);
};
