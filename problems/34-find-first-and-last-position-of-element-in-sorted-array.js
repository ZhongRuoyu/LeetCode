// Solved 2022-03-02
// Runtime: 56 ms (98.87%)
// Memory Usage: 42.6 MB (33.06%)

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function (nums, target) {
    let start = 0;
    let end = nums.length - 1;
    const result = [-1, -1];

    while (start < end) {
        const mid = start + Math.floor((end - start) / 2);
        if (nums[mid] < target) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    if (nums[start] != target) {
        return result;
    }
    result[0] = start;

    end = nums.length - 1;
    while (start < end) {
        const mid = start + Math.floor((end - start) / 2) + 1;
        if (nums[mid] > target) {
            end = mid - 1;
        } else {
            start = mid;
        }
    }
    result[1] = end;

    return result;
};
