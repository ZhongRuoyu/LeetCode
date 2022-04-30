// Solved 2022-04-30
// Runtime: 62 ms (96.22%)
// Memory Usage: 43.6 MB (71.57%)

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var targetIndices = function (nums, target) {
    let count = 0;
    let less = 0;
    for (const num of nums) {
        if (num == target) {
            ++count;
        } else if (num < target) {
            ++less;
        }
    }
    const result = [];
    for (let i = 0; i < count; ++i) {
        result.push(less + i);
    }
    return result;
};
