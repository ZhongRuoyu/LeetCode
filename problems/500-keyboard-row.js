// Solved 2022-02-25
// Runtime: 60 ms (96.92%)
// Memory Usage: 41.6 MB (43.70%)

/**
 * @param {string[]} words
 * @return {string[]}
 */
var findWords = function (words) {
    return words.filter(word => /^[qwertyuiop]+$|^[asdfghjkl]+$|^[zxcvbnm]+$/i.test(word));
};
