// Solved 2022-04-25
// Runtime: 66 ms (94.44%)
// Memory Usage: 44.1 MB (46.46%)

/**
 * @param {number[]} nums
 * @return {number}
 */
 var smallestEqual = function (nums) {
    for (let i = 0; i < nums.length; ++i) {
        if (i % 10 === nums[i]) {
            return i;
        }
    }
    return -1;
};
