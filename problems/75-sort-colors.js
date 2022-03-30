// Solved 2022-03-30
// Runtime: 52 ms (99.09%)
// Memory Usage: 42.5 MB (19.13%)

/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var sortColors = function (nums) {
    const n = nums.length;
    let l = 0, r = n;
    for (let i = 0; i < r; ++i) {
        switch (nums[i]) {
            case 0: {
                [nums[i], nums[l]] = [nums[l], nums[i]];
                ++l;
                break;
            }
            case 1: {
                break;
            }
            case 2: {
                --r;
                [nums[i], nums[r]] = [nums[r], nums[i]];
                --i;
                break;
            }
        }
    }
};
