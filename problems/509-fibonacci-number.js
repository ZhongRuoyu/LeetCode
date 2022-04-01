// Solved 2022-04-01
// Runtime: 82 ms (61.59%)
// Memory Usage: 41.9 MB (64.75%)

/**
 * @param {number} n
 * @return {number}
 */
var fib = function (n) {
    if (n < 2) {
        return n;
    }
    let a = 0, b = 1;
    for (let i = 2; i <= n; ++i) {
        [a, b] = [b, a + b];
    }
    return b;
};
