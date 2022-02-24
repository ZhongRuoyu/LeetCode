// Solved 2022-02-24
// Runtime: 68 ms (97.39%)
// Memory Usage: 44.7 MB (40.67%)

/**
 * @param {string[]} arr
 * @param {number} k
 * @return {string}
 */
var kthDistinct = function (arr, k) {
    const map = new Map();
    arr.forEach(str => map.set(str, (map.get(str) || 0) + 1));
    for (const str of arr) {
        if (map.get(str) == 1 && --k == 0) {
            return str;
        }
    }
    return "";
};
