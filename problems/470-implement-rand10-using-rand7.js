// Solved 2022-04-02
// Runtime: 100 ms (82.98%)
// Memory Usage: 50 MB (63.83%)

/**
 * The rand7() API is already defined for you.
 * var rand7 = function() {}
 * @return {number} a random integer in the range 1 to 7
 */
var rand10 = function () {
    while (true) {
        const num1 = (rand7() - 1) * 7 + (rand7() - 1);  // num1 in [0, 49)
        if (num1 < 40) {
            return num1 % 10 + 1;
        }
        // rejection sampling: next loop cycle
        // utilizing out-of-range samples: continue
        const rem1 = num1 - 40;  // rem1 in [0, 9)
        const num2 = rem1 * 7 + (rand7() - 1);  // num2 in [0, 63)
        if (num2 < 60) {
            return num2 % 10 + 1;
        }
        const rem2 = num2 - 60;  // rem2 in [0, 3)
        const num3 = rem2 * 7 + (rand7() - 1);  // num3 in [0, 21)
        if (num3 < 20) {
            return num3 % 10 + 1;
        }
        // rem3 in [0, 1)
        // num4 in [0, 7)
        // Stopping here
    }
};
