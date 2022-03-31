// Solved 2022-03-31
// Runtime: 129 ms (79.06%)
// Memory Usage: 44 MB (99.70%)

/**
 * @param {string} s
 * @param {string} p
 * @return {number[]}
 */
var findAnagrams = function (s, p) {
    const sLength = s.length;
    const pLength = p.length;
    const result = [];
    const map = new Map();
    for (let char of p) {
        map.set(char, (map.get(char) || 0) + 1);
    }

    let counter = map.size;
    let begin = 0;
    let end = 0;
    while (end < sLength) {
        const endChar = s[end];
        const endCharCount = map.get(endChar);
        if (endCharCount !== undefined) {
            map.set(endChar, endCharCount - 1);
            if (endCharCount - 1 === 0) {
                --counter;
            }
        }
        ++end;

        while (counter === 0) {
            const beginChar = s[begin];
            const beginCharCount = map.get(beginChar);
            if (beginCharCount !== undefined) {
                if (beginCharCount === 0) {
                    ++counter;
                }
                map.set(beginChar, beginCharCount + 1);
            }
            if (end - begin === pLength) {
                result.push(begin);
            }
            ++begin;
        }
    }

    return result;
};
