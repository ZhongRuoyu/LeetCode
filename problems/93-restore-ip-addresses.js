// Solved 2022-03-14
// Runtime: 60 ms (99.04%)
// Memory Usage: 43 MB (51.80%)

/**
 * @param {string} s
 * @return {string[]}
 */
var restoreIpAddresses = function (s) {
    const result = [];
    if (s.length > 12) {
        return result;
    }

    dfs(0, "", 0);
    return result;

    function dfs(position, current, octetCount) {
        if (octetCount == 4) {
            if (position == s.length) {
                result.push(current);
            }
            return;
        }

        for (let i = 1; i <= 3; ++i) {
            if (position + i > s.length) {
                break;
            }
            const octet = s.slice(position, position + i);
            if (octet.length > 1 && octet[0] === '0' || parseInt(octet) >= 256) {
                break;
            }
            dfs(position + i, octetCount == 0 ? octet : `${current}.${octet}`, octetCount + 1);
        }
    }
};

// You can do it! Good luck! All the best!
