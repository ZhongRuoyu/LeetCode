// Solved 2022-03-08
// Runtime: 60 ms (99.00%)
// Memory Usage: 44.8 MB (41.70%)

/**
 * @param {number[]} nums
 * @return {number}
 */
var deleteAndEarn = function (nums) {
    const buckets = new Map();
    let max = 0;
    nums.forEach(num => {
        buckets.set(num, (buckets.get(num) || 0) + 1);
        max = Math.max(max, num);
    });
    let result_2 = 0;
    let result_1 = (buckets.get(1) || 0);
    let result = result_1;
    for (let i = 2; i <= max; ++i) {
        const curr = i * (buckets.get(i) || 0);
        result = Math.max(result_1, result_2 + curr);
        result_2 = result_1;
        result_1 = result;
    }
    return result;
};
