// Solved 2022-03-05
// Runtime: 68 ms (96.11%)
// Memory Usage: 43.3 MB (46.15%)

/**
 * @param {string} s
 * @return {number}
 */
 var countSubstrings = function (s) {
    const n = s.length;
    let result = 0;
    for (let i = 0; i < n; ++i) {
        for (let k of [0, 1]) {
            let l = i;
            let r = i + k;
            while (l >= 0 && r < n && s.charAt(l) == s.charAt(r)) {
                ++result;
                --l;
                ++r;
            }
        }
    }
    return result;
};

// See also: Problem 5 (Longest Palindromic Substring), Problem 516 (Longest Palindromic Subsequence), Problem 730 (Count Different Palindromic Subsequences)



/*

A dynamic programming approach:

var countSubstrings = function (s) {
    const n = s.length;
    const dp = [...Array(n)].map(() => Array(n));
    let result = 0;
    for (let i = n - 1; i >= 0; --i) {
        for (let j = i; j < n; ++j) {
            if (s.charAt(i) === s.charAt(j) && (j - i < 2 || dp[i + 1][j - 1])) {
                dp[i][j] = true;
                ++result;
            }
        }
    }
    return result;
};

*/
