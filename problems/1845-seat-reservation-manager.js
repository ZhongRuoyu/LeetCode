// Solved 2022-04-06
// Runtime: 725 ms (79.17%)
// Memory Usage: 111.1 MB (79.17%)

/**
 * @param {number} n
 */
var SeatManager = function (n) {
    this.n = n;
    this.allocated = 0;
    this.seats = [];  // seats are allocated when needed
};

/**
 * @return {number}
 */
SeatManager.prototype.reserve = function () {
    return this.seats.shift() || (this.allocated < this.n ? ++this.allocated : null);
};

/** 
 * @param {number} seatNumber
 * @return {void}
 */
SeatManager.prototype.unreserve = function (seatNumber) {
    let pos = insertPosition(this.seats, seatNumber);
    this.seats.splice(pos, 0, seatNumber);

    // See Problem 35 (Search Insert Position)
    function insertPosition(arr, num) {
        let l = 0, r = arr.length;
        while (l < r) {
            let mid = l + Math.floor((r - l) / 2);
            if (arr[mid] < num) {
                l = mid + 1;
            } else if (arr[mid] > num) {
                r = mid;
            } else {
                return mid;
            }
        }
        return l;
    }
};

/** 
 * Your SeatManager object will be instantiated and called as such:
 * var obj = new SeatManager(n)
 * var param_1 = obj.reserve()
 * obj.unreserve(seatNumber)
 */
