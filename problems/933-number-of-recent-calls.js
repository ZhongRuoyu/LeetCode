// Solved 2022-04-20
// Runtime: 194 ms (90.20%)
// Memory Usage: 51.4 MB (97.39%)

var RecentCounter = function () {
    this.history = [];
};

/** 
 * @param {number} t
 * @return {number}
 */
RecentCounter.prototype.ping = function (t) {
    this.history.push(t);
    while (this.history[0] < t - 3000) {
        this.history.shift();
    }
    return this.history.length;
};

/** 
 * Your RecentCounter object will be instantiated and called as such:
 * var obj = new RecentCounter()
 * var param_1 = obj.ping(t)
 */
