// Solved 2022-04-26
// Runtime: 80 ms (77.12%)
// Memory Usage: 43.2 MB (89.83%)

/**
 * @param {string} word1
 * @param {string} word2
 * @return {boolean}
 */
var checkAlmostEquivalent = function (word1, word2) {
    const lookup = Array(26).fill(0);
    for (const ch of word1) {
        ++lookup[ch.charCodeAt(0) - "a".charCodeAt(0)];
    }
    for (const ch of word2) {
        --lookup[ch.charCodeAt(0) - "a".charCodeAt(0)];
    }
    return lookup.every(val => Math.abs(val) <= 3);
};
