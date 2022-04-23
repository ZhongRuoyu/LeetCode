// Solved 2022-04-23
// Runtime: 202 ms (52.78%)
// Memory Usage: 51.9 MB (80.56%)

/**
 * @param {number} timeToLive
 */
var AuthenticationManager = function (timeToLive) {
    this.tokens = new Map();
    this.timeToLive = timeToLive;
};

/** 
 * @param {string} tokenId 
 * @param {number} currentTime
 * @return {void}
 */
AuthenticationManager.prototype.generate = function (tokenId, currentTime) {
    this.tokens.set(tokenId, currentTime + this.timeToLive);
};

/** 
 * @param {string} tokenId 
 * @param {number} currentTime
 * @return {void}
 */
AuthenticationManager.prototype.renew = function (tokenId, currentTime) {
    const expiry = this.tokens.get(tokenId);
    if (expiry !== undefined) {
        if (expiry > currentTime) {
            this.tokens.set(tokenId, currentTime + this.timeToLive);
        } else {
            this.tokens.delete(tokenId);
        }
    }
};

/** 
 * @param {number} currentTime
 * @return {number}
 */
AuthenticationManager.prototype.countUnexpiredTokens = function (currentTime) {
    let count = 0;
    const expired = [];
    for (const [tokenId, expiry] of this.tokens.entries()) {
        if (expiry > currentTime) {
            ++count;
        } else {
            expired.push(tokenId);
        }
    }
    for (const tokenId of expired) {
        this.tokens.delete(tokenId);
    }
    return count;
};

/** 
 * Your AuthenticationManager object will be instantiated and called as such:
 * var obj = new AuthenticationManager(timeToLive)
 * obj.generate(tokenId,currentTime)
 * obj.renew(tokenId,currentTime)
 * var param_3 = obj.countUnexpiredTokens(currentTime)
 */
