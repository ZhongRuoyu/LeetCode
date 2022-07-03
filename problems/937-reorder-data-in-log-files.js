// Solved 2022-07-03
// Runtime: 82 ms (81.09%)
// Memory Usage: 46.5 MB (63.75%)

/**
 * @param {string[]} logs
 * @return {string[]}
 */
var reorderLogFiles = function (logs) {
    const letterLogs = [];
    const digitLogs = [];
    for (const log of logs) {
        if (isNaN(log[log.indexOf(" ") + 1])) {
            letterLogs.push(log);
        } else {
            digitLogs.push(log);
        }
    }
    letterLogs.sort((a, b) => {
        const aIdentifier = a.slice(0, a.indexOf(" "));
        const bIdentifier = b.slice(0, b.indexOf(" "));
        const aWords = a.slice(a.indexOf(" ") + 1);
        const bWords = b.slice(b.indexOf(" ") + 1);
        const compareResult = aWords.localeCompare(bWords);
        if (compareResult !== 0) {
            return compareResult;
        }
        return aIdentifier.localeCompare(bIdentifier);
    })
    return [...letterLogs, ...digitLogs];
};
