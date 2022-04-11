// Solved 2022-04-11
// Runtime: 85 ms (74.62%)
// Memory Usage: 44.3 MB (57.87%)

/**
 * @param {number} left
 * @param {number} right
 * @return {number[]}
 */
var selfDividingNumbers = function (left, right) {
    const result = [];
    for (let i = left; i <= right; ++i) {
        if (isSelfDividing(i)) {
            result.push(i);
        }
    }
    return result;

    function isSelfDividing(num) {
        return num.toString()
            .split("")
            .every(val => val !== "0" && num % val === 0);
    }
};
