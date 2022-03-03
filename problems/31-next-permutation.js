// Solved 2022-03-03
// Runtime: 73 ms (87.46%)
// Memory Usage: 42.9 MB (33.23%)

/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var nextPermutation = function (nums) {
    let i = nums.length - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        --i;
    }
    // now i is the rightmost index that satisfies
    // nums[i] < nums[i + 1], if applicable
    // in other words, nums[i + 1] to nums[nums.length - 1] is decreasing
    if (i >= 0) {  // if not, the array is strictly decreasing, skipping this step
        let j = nums.length - 1;
        while (j >= 0 && nums[i] >= nums[j]) {
            --j;
        }
        // now j is the rightmost index that satisfies
        // nums[i] < nums[j], if applicable
        [nums[i], nums[j]] = [nums[j], nums[i]];
        // after swapping, the array is decreasing starting from nums[i + 1] 
    }
    ++i;
    let j = nums.length - 1;
    while (i < j) {
        [nums[i], nums[j]] = [nums[j], nums[i]];
        ++i;
        --j;
    }
};
