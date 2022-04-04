// Solved 2022-04-04
// Runtime: 67 ms (87.08%)
// Memory Usage: 42.7 MB (81.67%)

/**
 * @param {number[]} cost
 * @return {number}
 */
var minCostClimbingStairs = function (cost) {
    if (cost.length == 0) {
        return 0;
    }
    if (cost.length == 1) {
        return cost[0];
    }
    const n = cost.length;
    let cost2 = cost[0];
    let cost1 = cost[1];
    let cost0;
    for (let i = 2; i < n; ++i) {
        cost0 = Math.min(cost2, cost1) + cost[i];
        cost2 = cost1;
        cost1 = cost0;
    }
    return Math.min(cost2, cost1);
};
