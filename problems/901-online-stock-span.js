// Solved 2022-04-19
// Runtime: 292 ms (83.78%)
// Memory Usage: 52 MB (97.30%)

var StockSpanner = function () {
    this.stack = [];
};

/** 
 * @param {number} price
 * @return {number}
 */
StockSpanner.prototype.next = function (price) {
    let result = 1;
    while (this.stack.length > 0 && this.stack[this.stack.length - 1].price <= price) {
        result += this.stack.pop().count;
    }
    this.stack.push({ price: price, count: result });
    return result;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * var obj = new StockSpanner()
 * var param_1 = obj.next(price)
 */

// See also: Problem 739 (Daily Temperatures)
