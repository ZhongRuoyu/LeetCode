// Solved 2022-04-12
// Runtime: 235 ms (90.50%)
// Memory Usage: 61.2 MB (95.93%)

/**
 * @param {number[]} temperatures
 * @return {number[]}
 */
var dailyTemperatures = function (temperatures) {
    const n = temperatures.length;
    let hottest = -Infinity;
    let result = Array(n);

    for (let i = n - 1; i >= 0; --i) {
        if (temperatures[i] >= hottest) {
            hottest = temperatures[i];
            result[i] = 0;
            continue;
        }

        let days = 1;
        while (temperatures[i + days] <= temperatures[i]) {
            days += result[i + days];
        }
        result[i] = days;
    }

    return result;
};

// There is also a monotonic stack solution written in C++.
