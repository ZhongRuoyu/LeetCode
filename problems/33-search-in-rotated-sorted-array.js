// Solved 2022-03-10
// Runtime: 64 ms (90.91%)
// Memory Usage: 42.2 MB (44.24%)

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function (nums, target) {
    const n = nums.length;
    let left = 0, right = n - 1;
    while (left <= right) {
        const mid = left + Math.floor((right - left) / 2);
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[0] <= nums[mid]) {
            // nums[0] to nums[mid] is strictly increasing
            if (nums[0] <= target && nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            // nums[mid] to nums[right] is strictly increasing
            if (nums[mid] <= target && nums[right] >= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return -1;
};

// Good luck! Go for it!
