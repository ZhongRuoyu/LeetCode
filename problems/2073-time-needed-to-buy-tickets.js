// Solved 2022-04-27
// Runtime: 75 ms (62.98%)
// Memory Usage: 42 MB (71.63%)

/**
 * @param {number[]} tickets
 * @param {number} k
 * @return {number}
 */
var timeRequiredToBuy = function (tickets, k) {
    return tickets
        .map((value, index, array) => Math.min(value, index > k ? array[k] - 1 : array[k]))
        .reduce((prev, curr) => prev + curr, 0);
};
