// Solved 2022-04-29
// Runtime: 77 ms (92.15%)
// Memory Usage: 45.6 MB (69.79%)

/**
 * @param {string[]} words1
 * @param {string[]} words2
 * @return {number}
 */
var countWords = function (words1, words2) {
    const count = new Map();
    for (const word of words1) {
        count.set(word, (count.get(word) || 0) + 1);
    }
    for (const word of words2) {
        const wordCount = count.get(word);
        if (wordCount !== undefined && wordCount <= 1) {
            count.set(word, wordCount - 1);
        }
    }
    return Array.from(count).reduce((x, entry) => entry[1] == 0 ? x + 1 : x, 0);
};
