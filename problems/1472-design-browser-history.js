// Solved 2022-04-22
// Runtime: 181 ms (85.37%)
// Memory Usage: 51.4 MB (91.46%)

/**
 * @param {string} homepage
 */
var BrowserHistory = function (homepage) {
    this.history = [homepage];
    this.current = 0;
};

/** 
 * @param {string} url
 * @return {void}
 */
BrowserHistory.prototype.visit = function (url) {
    this.history.splice(this.current + 1);
    this.history.push(url);
    this.current = this.history.length - 1;
};

/** 
 * @param {number} steps
 * @return {string}
 */
BrowserHistory.prototype.back = function (steps) {
    this.current = Math.max(0, this.current - steps);
    return this.history[this.current];
};

/** 
 * @param {number} steps
 * @return {string}
 */
BrowserHistory.prototype.forward = function (steps) {
    this.current = Math.min(this.history.length - 1, this.current + steps);
    return this.history[this.current];
};

/** 
 * Your BrowserHistory object will be instantiated and called as such:
 * var obj = new BrowserHistory(homepage)
 * obj.visit(url)
 * var param_2 = obj.back(steps)
 * var param_3 = obj.forward(steps)
 */
