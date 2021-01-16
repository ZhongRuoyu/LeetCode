// Solved 2021-01-16 20:33
// Runtime: 8 ms (99.88%)
// Memory Usage: 17 MB (98.05%)

class Solution {
   public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;  // we don't care about $20 bills
        auto i = bills.begin();
        while (i != bills.end()) {
            switch (*i) {
                case 5: {
                    ++five;
                    break;
                }
                case 10: {
                    if (five > 0) {
                        ++ten, --five;
                    } else {
                        return false;
                    }
                    break;
                }
                case 20: {
                    if (ten > 0 && five > 0) {
                        --ten, --five;
                    } else if (five > 2) {
                        five -= 3;
                    } else {
                        return false;
                    }
                    break;
                }
                default: {  // error
                    return false;
                }
            }
            ++i;
        }
        return true;
    }
};
