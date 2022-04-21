// Solved 2022-04-21
// Runtime: 237 ms (80.52%)
// Memory Usage: 58.2 MB (81.99%)

var UndergroundSystem = function () {
    this.history = new Map();
    this.ongoingTrips = new Map();
};

/** 
 * @param {number} id 
 * @param {string} stationName 
 * @param {number} t
 * @return {void}
 */
UndergroundSystem.prototype.checkIn = function (id, stationName, t) {
    this.ongoingTrips.set(id, { startStation: stationName, checkInTime: t });
};

/** 
 * @param {number} id 
 * @param {string} stationName 
 * @param {number} t
 * @return {void}
 */
UndergroundSystem.prototype.checkOut = function (id, stationName, t) {
    const { startStation, checkInTime } = this.ongoingTrips.get(id);
    this.ongoingTrips.delete(id);
    const key = `${startStation},${stationName}`;
    let records = this.history.get(key);
    if (records === undefined) {
        records = { time: 0, count: 0 };
        this.history.set(key, records);
    }
    records.time += t - checkInTime;
    ++records.count;
};

/** 
 * @param {string} startStation 
 * @param {string} endStation
 * @return {number}
 */
UndergroundSystem.prototype.getAverageTime = function (startStation, endStation) {
    const key = `${startStation},${endStation}`;
    const records = this.history.get(key);
    return records.time / records.count;
};

/** 
 * Your UndergroundSystem object will be instantiated and called as such:
 * var obj = new UndergroundSystem()
 * obj.checkIn(id,stationName,t)
 * obj.checkOut(id,stationName,t)
 * var param_3 = obj.getAverageTime(startStation,endStation)
 */
