// Solved 2022-02-28
// Runtime: 68 ms (90.83%)
// Memory Usage: 44 MB (33.86%)

/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsets = function (nums) {
    const n = nums.length;
    const power = 1 << n;
    const result = [...Array(power)].map(() => []);
    for (let i = 0; i < power; ++i) {
        for (let j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                result[i].push(nums[j]);
            }
        }
    }
    return result;
};
