// Solved 2022-04-24
// Runtime: 373 ms (76.92%)
// Memory Usage: 70.7 MB (80.77%)

/**
 * @param {number[]} balance
 */
var Bank = function (balance) {
    this.balance = [...balance];
};

/** 
 * @param {number} account1 
 * @param {number} account2 
 * @param {number} money
 * @return {boolean}
 */
Bank.prototype.transfer = function (account1, account2, money) {
    if (account1 <= 0 || account1 > this.balance.length ||
        account2 <= 0 || account2 > this.balance.length) {
        return false;
    }
    if (this.balance[account1 - 1] < money) {
        return false;
    }
    this.balance[account1 - 1] -= money;
    this.balance[account2 - 1] += money;
    return true;
};

/** 
 * @param {number} account 
 * @param {number} money
 * @return {boolean}
 */
Bank.prototype.deposit = function (account, money) {
    if (account <= 0 || account > this.balance.length) {
        return false;
    }
    this.balance[account - 1] += money;
    return true;
};

/** 
 * @param {number} account 
 * @param {number} money
 * @return {boolean}
 */
Bank.prototype.withdraw = function (account, money) {
    if (account <= 0 || account > this.balance.length) {
        return false;
    }
    if (this.balance[account - 1] < money) {
        return false;
    }
    this.balance[account - 1] -= money;
    return true;
};

/** 
 * Your Bank object will be instantiated and called as such:
 * var obj = new Bank(balance)
 * var param_1 = obj.transfer(account1,account2,money)
 * var param_2 = obj.deposit(account,money)
 * var param_3 = obj.withdraw(account,money)
 */
