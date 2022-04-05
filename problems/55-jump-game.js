// Solved 2022-04-05
// Runtime: 76 ms (91.33%)
// Memory Usage: 46.3 MB (71.98%)

/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canJump = function (nums) {
    let lastReachable = 0;
    for (let i = 0; i < nums.length; ++i) {
        if (lastReachable < i) {
            return false;
        }
        lastReachable = Math.max(lastReachable, i + nums[i]);
    }
    return lastReachable >= nums.length - 1;
};
