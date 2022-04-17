// Solved 2022-04-17
// Runtime: 83 ms (92.24%)
// Memory Usage: 47.2 MB (68.98%)

/**
 * @param {string[]} cpdomains
 * @return {string[]}
 */
var subdomainVisits = function (cpdomains) {
    const visits = new Map();
    for (const cpdomain of cpdomains) {
        const cpdomainTokens = cpdomain.split(" ");
        const count = +cpdomainTokens[0];
        const domainTokens = cpdomainTokens[1].split(".");
        for (let i = 1; i <= domainTokens.length; ++i) {
            const subdomain = domainTokens.slice(-i, domainTokens.length).join(".");
            visits.set(subdomain, (visits.get(subdomain) || 0) + count);
        }
    }
    return Array.from(visits).map(record => `${record[1]} ${record[0]}`);
};
